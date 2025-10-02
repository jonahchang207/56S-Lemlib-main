#include "main.h"
#include "subsystems.hpp"
#include "touchscreen.hpp"
#include "auton/registry.hpp"
#include <vector>
#include <string>

static lv_obj_t* auton_options = nullptr;
static lv_obj_t* skills_options = nullptr;
static lv_obj_t* auton_desc_label = nullptr;
static int selected_auton = 0;


static void btn_event_cb(lv_event_t* e) {
    lv_obj_t* btn = (lv_obj_t*)lv_event_get_target(e);
    int btn_id = (int)(intptr_t)lv_obj_get_user_data(btn);
    selected_auton = btn_id;

    // Clear all button highlights in auton_options (and skills_options if present)
    lv_obj_t* containers[] = { auton_options, skills_options };
    for (int j = 0; j < 2; j++) {
        if (containers[j] != nullptr) {
            uint32_t count = lv_obj_get_child_count(containers[j]);
            for (uint32_t i = 0; i < count; i++) {
                lv_obj_t* child = lv_obj_get_child(containers[j], i);
                if (!child) continue;
                // Best-effort: set button style for any child (non-buttons will ignore extra styles)
                lv_obj_set_style_bg_color(child, lv_color_hex(0x2A2A2A), 0);
                lv_obj_set_style_text_color(child, lv_color_hex(0xFFFFFF), 0);
            }
        }
    }

    // Highlight the pressed button with a subtle lighter gray
    lv_obj_set_style_bg_color(btn, lv_color_hex(0x555555), 0);
    lv_obj_set_style_text_color(btn, lv_color_hex(0x000000), 0);

    // Update description label
    const auto& list = auton::Registry::instance().autons();
    if (auton_desc_label) {
        if (btn_id >= 0 && btn_id < (int)list.size()) {
            lv_label_set_text(auton_desc_label, list[btn_id]->name());
        } else {
            lv_label_set_text(auton_desc_label, "N/A");
        }
    }

    // update any other UI state
    // (call a small function to update bottom label)
    // defined later
    extern void update_match_data();
    update_match_data();
}

static lv_obj_t* label_x = nullptr;
static lv_obj_t* label_y = nullptr;
static lv_obj_t* label_theta = nullptr;
static lv_obj_t* dd_auton = nullptr;
static int auton_index = 0;

static void auton_event_cb(lv_event_t* e) {
    if (!dd_auton) return;
    auton_index = (int)lv_dropdown_get_selected(dd_auton);
}

static void ui_update_timer(lv_timer_t* t) {
    (void)t;
    auto odomPose = chassis.getPose();
    
    if (label_x) {
        std::string x_str = "X: " + std::to_string(odomPose.x);
        lv_label_set_text(label_x, x_str.c_str());
    }
    if (label_y) {
        std::string y_str = "Y: " + std::to_string(odomPose.y);
        lv_label_set_text(label_y, y_str.c_str());
    }
    if (label_theta) {
        std::string theta_str = "Theta: " + std::to_string(lemlib::radToDeg(odomPose.theta));
        lv_label_set_text(label_theta, theta_str.c_str());
    }
}



void touchscreen_int() {

    // ensure LVGL is initialized by PROS llemu template; get the default display
    lv_display_t* disp = lv_display_get_default();
    lv_obj_t* scr = nullptr;
    if (disp) {
        scr = lv_display_get_screen_active(disp);
        // clear any existing LVGL children on the active screen so we start clean
        if (scr) lv_obj_clean(scr);
    }

    // Title
    lv_obj_t* title = lv_label_create(scr);
    lv_label_set_text(title, "Auton Selector & Pose");
    // Minimalist styling: white text on black
    lv_obj_set_style_text_color(title, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 6);

    // --- AUTON SELECTOR (button-based, populated from registry) ---
    // Create description label on the right
    auton_desc_label = lv_label_create(scr);
    lv_obj_set_width(auton_desc_label, 200);
    lv_obj_align(auton_desc_label, LV_ALIGN_TOP_RIGHT, -5, 36);
    lv_obj_set_style_text_font(auton_desc_label, &lv_font_montserrat_10, 0);
    lv_obj_set_style_text_color(auton_desc_label, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_bg_opa(auton_desc_label, 0, 0);
    lv_label_set_text(auton_desc_label, "Select an autonomous routine.");

    // Create vertical container for auton buttons
    auton_options = lv_obj_create(scr);
    lv_obj_set_size(auton_options, 200, 150);
    lv_obj_align(auton_options, LV_ALIGN_TOP_LEFT, 10, 36);
    // container sits on black background; keep it transparent
    lv_obj_set_style_bg_opa(auton_options, 0, 0);
    lv_obj_set_flex_flow(auton_options, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scroll_dir(auton_options, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(auton_options, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_style_pad_row(auton_options, 3, 0);

    // Create buttons for each registered auton
    const auto& list = auton::Registry::instance().autons();
    for (int i = 0; i < (int)list.size(); ++i) {
        // lv_btn_create is not available in this LVGL build; create a generic object and style it like a button
        lv_obj_t* btn = lv_obj_create(auton_options);
    // Minimalist button: dark gray on black, white text, no border
    lv_obj_set_size(btn, 180, 25);
    lv_obj_set_style_bg_color(btn, lv_color_hex(0x333333), 0);
    lv_obj_set_style_border_width(btn, 0, 0);
    lv_obj_set_style_radius(btn, 0, 0);
    lv_obj_set_style_text_color(btn, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_font(btn, &lv_font_montserrat_10, 0);

    lv_obj_t* label = lv_label_create(btn);
    lv_label_set_text(label, list[i]->name());
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_user_data(btn, (void*)(intptr_t)i);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL);
    }

    // Pose labels
    label_x = lv_label_create(scr);
    lv_label_set_text(label_x, "X: 0.00");
    lv_obj_align(label_x, LV_ALIGN_CENTER, 0, -10);

    label_y = lv_label_create(scr);
    lv_label_set_text(label_y, "Y: 0.00");
    lv_obj_align(label_y, LV_ALIGN_CENTER, 0, 10);

    label_theta = lv_label_create(scr);
    lv_label_set_text(label_theta, "Theta: 0.00");
    lv_obj_align(label_theta, LV_ALIGN_CENTER, 0, 30);

    // Create a timer to update the labels at 20 Hz (50ms)
    lv_timer_create(ui_update_timer, 50, NULL);
}

int ui::selected_auton() {
    return (int)selected_auton;
}

void update_match_data() {
    static lv_obj_t* auton_label = nullptr;
    if (!auton_label) {
        lv_display_t* disp = lv_display_get_default();
        lv_obj_t* scr = nullptr;
        if (disp) scr = lv_display_get_screen_active(disp);
        auton_label = lv_label_create(scr);
    lv_obj_set_style_text_font(auton_label, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(auton_label, lv_color_hex(0xFFFFFF), 0);
        lv_obj_align(auton_label, LV_ALIGN_BOTTOM_MID, 0, -10);
    }
    const auto& list = auton::Registry::instance().autons();
    if (selected_auton >= 0 && selected_auton < (int)list.size()) {
        lv_label_set_text(auton_label, list[selected_auton]->name());
    } else {
        lv_label_set_text(auton_label, "N/A");
    }
}

// Background task that waits for enable to update selection (kept minimal)
pros::Task selected_auton_update([]() {
    while (true) {
        pros::delay(100);
    }
});
