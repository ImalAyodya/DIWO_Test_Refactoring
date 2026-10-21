#include <stdio.h>

static int global_odometer_pulses = 0;

int get_global_odometer_pulses(void) {
    return global_odometer_pulses;
}

void set_global_odometer_pulses(int value) {
    global_odometer_pulses = value;
}


void record_odometer_pulse() {
    set_global_odometer_pulses(get_global_odometer_pulses() + 1);
}

int main() {
    record_odometer_pulse();
    printf("Odometer: %d\n", get_global_odometer_pulses());
    return 0;
}
