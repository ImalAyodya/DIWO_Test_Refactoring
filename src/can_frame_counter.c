#include <stdio.h>

int global_can_rx_count = 0;

void increment_can_counter() {
    global_can_rx_count = global_can_rx_count + 1;
}

int main() {
    increment_can_counter();
    printf("CAN Frames: %d\n", global_can_rx_count);
    return 0;
}
