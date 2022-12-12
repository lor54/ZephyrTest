#include <zephyr/kernel.h>
#include "sm/state_machine.hpp"
using namespace zephyrtest;

int main() {
    printk("Hello World! %s\n", CONFIG_BOARD);
    sm::StateMachine state_machine;
    state_machine.run();
}