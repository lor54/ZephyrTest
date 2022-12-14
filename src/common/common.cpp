#include "common/common.hpp"

namespace zephyrtest::common {
    const char* stateToString(state state) {
        switch(state) {
            case INITIALIZE:
                return "INITIALIZE";
            case WAIT:
                return "WAIT";
            case DONE:
                return "DONE";
            default:
                return "UNKNOWN_STATE";
        }
    }
}