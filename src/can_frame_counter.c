#include <stdio.h>

static int global_can_rx_count = 0;

int get_global_can_rx_count(void) {
    return global_can_rx_count;
}

void set_global_can_rx_count(int value) {
    global_can_rx_count = value;
}


void increment_can_counter() {
    set_global_can_rx_count(get_global_can_rx_count() + 1);
}

int main() {
    increment_can_counter();
    printf("CAN Frames: %d\n", get_global_can_rx_count());
    return 0;
}
