#include "auton/registry.hpp"

namespace auton {

Registry& Registry::instance() {
    static Registry r;
    return r;
}

void Registry::registerAuton(Auton* a) {
    list_.push_back(a);
}

const std::vector<Auton*>& Registry::autons() const {
    return list_;
}

Registrar::Registrar(Auton* a) {
    Registry::instance().registerAuton(a);
}

} // namespace auton
