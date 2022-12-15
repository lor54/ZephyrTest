#include "controller.hpp"

#define PRIORITY 7
#define STACK_SIZE 1024
K_THREAD_STACK_DEFINE(sm_stack_area, STACK_SIZE);

namespace zephyrtest::controller {
    Controller::Controller(sm::StateMachine& sm) : state_machine {sm} {
        k_thread_create(&sm_thread, sm_stack_area, K_THREAD_STACK_SIZEOF(sm_stack_area), update, this, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
        k_thread_name_set(&sm_thread, "sm_thread");
    }

    Controller::~Controller() = default;

    void Controller::run() {
        //int32_t ret = state_machine.execute();
    }

    void Controller::update(void* instance, void *, void *) {
        auto controller = reinterpret_cast<Controller*>(instance);
        if (!controller) return;

        controller->state_machine.execute();
        return;
    }
}