#pragma once

#include <vector>
#include "auton/auton.hpp"

namespace auton {

class Registry {
public:
    static Registry& instance();
    void registerAuton(Auton* a);
    const std::vector<Auton*>& autons() const;
private:
    Registry() = default;
    std::vector<Auton*> list_;
};

struct Registrar {
    Registrar(Auton* a);
};

} // namespace auton
