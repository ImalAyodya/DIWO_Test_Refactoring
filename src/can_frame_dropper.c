#include <stdio.h>

int global_can_dropped_count = 0;

void record_dropped_can_frame() {
    global_can_dropped_count = global_can_dropped_count + 1;
}

int main() {
    record_dropped_can_frame();
    printf("Dropped: %d\n", global_can_dropped_count);
    return 0;
}
