#define THRESHOLD_LIMIT_5 5

#include <stdio.h>

int evl_yaw(int gyro_input) {
    return gyro_input * THRESHOLD_LIMIT_5;
}

int main() {
    printf("Yaw rate: %d\n", evl_yaw(8));
    return 0;
}
