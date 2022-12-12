#include <zephyr/kernel.h>

int main() {
    printk("Hello World! %s\n", CONFIG_BOARD);
}