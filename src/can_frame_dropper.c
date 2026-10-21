#include <stdio.h>

static int global_can_dropped_count = 0;

int get_global_can_dropped_count(void) {
    return global_can_dropped_count;
}

void set_global_can_dropped_count(int value) {
    global_can_dropped_count = value;
}


void record_dropped_can_frame() {
    set_global_can_dropped_count(get_global_can_dropped_count() + 1);
}

int main() {
    record_dropped_can_frame();
    printf("Dropped: %d\n", get_global_can_dropped_count());
    return 0;
}
