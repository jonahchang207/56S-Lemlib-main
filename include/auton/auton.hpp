#pragma once

namespace auton {

class Auton {
public:
    virtual ~Auton() = default;
    virtual void run() = 0;
    virtual const char* name() const = 0;
};

} // namespace auton
