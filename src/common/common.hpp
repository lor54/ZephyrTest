enum state { INITIALIZE, WAIT, DONE };

namespace zephyrtest::common {
    const char* stateToString(state state);
}