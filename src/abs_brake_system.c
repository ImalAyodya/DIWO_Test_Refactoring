#define THRESHOLD_LIMIT_25 25

#define THRESHOLD_LIMIT_4 4

#include <stdio.h>

int chk_slp(int wheel_speed) {
    return wheel_speed * THRESHOLD_LIMIT_4;
}

int main() {
    printf("Slip factor: %d\n", chk_slp(THRESHOLD_LIMIT_25));
    return 0;
}
