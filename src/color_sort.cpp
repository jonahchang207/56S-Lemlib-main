#include "color_sort.hpp"
#include "subsystems.hpp"

// Heuristic hue bands for red/blue detection under typical PROS Optical ranges [0..360)
// Red often appears near 0 or near 360 wrap; blue around ~200-260 depending on lighting.
static bool isRedHue(double hue) {
	return (hue >= 0 && hue <= 25) || (hue >= 335 && hue <= 360);
}

static bool isBlueHue(double hue) {
	return (hue >= 190 && hue <= 260);
}

void autonColorSort(SortColor color, bool enabled) {
	if (!enabled) {
		// Turn off LED and stop intakes when disabled
		optical.set_led_pwm(0);
        intake1.move(0);
        intake2.move(0);
		return;
	}

	// Ensure optical LED is on for reliable readings
	optical.set_led_pwm(100);

	// Read optical measurements
	double hue = optical.get_hue();
	int proximity = optical.get_proximity();

	// Basic validity check; require reasonable proximity to avoid background triggers
	bool has_object = (proximity > 60); // tune as needed
	bool match = false;
	if (hue != PROS_ERR_F) {
		if (color == SortColorRed) match = isRedHue(hue);
		else match = isBlueHue(hue);
	}

	if (has_object && match) {
        // Favor middle spin when target color detected: both positive
        int power = 127;
        intake1.move(power);   // top
        intake2.move(power);   // bottom
	} else {
		// Idle when not matching target
		intake1.move(0);
		intake2.move(0);
	}
}