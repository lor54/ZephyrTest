#include <zephyr/kernel.h>
#include "controller/controller.hpp"
using namespace zephyrtest;

int main() {
    printk("Hello World! %s\n", CONFIG_BOARD);

    sm::StateMachine state_machine;
    controller::Controller controller(state_machine);
    controller.run();

    while(1) {
        k_msleep(1000);
    }
}