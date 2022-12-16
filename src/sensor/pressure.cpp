#include <zephyr/kernel.h>
#include "pressure.hpp"

namespace zephyrtest::sensor {
    Pressure::Pressure() = default;
    Pressure::~Pressure() = default;

    float Pressure::getActualPressure() {
        return index < 1047 ? values[index++] : -1;
    }
}