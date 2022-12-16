#include <zephyr/kernel.h>
#include "pressure.hpp"

namespace zephyrtest::sensor {
    Pressure::Pressure() = default;
    Pressure::~Pressure() = default;

    float Pressure::getActualPressure() {
        k_msleep(250000);
        return index < 1047 ? values[index++] : -1;
    }

    float Pressure::getActualTemperature() {
        actualTemperature = index % 100 == 0 ? 30 - (0.65 * index/100) : actualTemperature;
        return index < 1047 ? actualTemperature : -1;
    }
}