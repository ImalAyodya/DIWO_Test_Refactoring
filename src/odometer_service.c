#include <stdio.h>

int global_odometer_pulses = 0;

void record_odometer_pulse() {
    global_odometer_pulses = global_odometer_pulses + 1;
}

int main() {
    record_odometer_pulse();
    printf("Odometer: %d\n", global_odometer_pulses);
    return 0;
}
