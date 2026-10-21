#include <stdio.h>

int clamp_fan_duty_cycle(int duty) {
    if (duty > 100) {
        return 100;
    }
    return duty;
}

int main() {
    printf("Duty: %d\n", clamp_fan_duty_cycle(75));
    return 0;
}
