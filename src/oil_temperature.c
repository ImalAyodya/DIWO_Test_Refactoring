#define THRESHOLD_LIMIT_1_5 1.5f

#include <stdio.h>

float rd_tmp(int channel_id) {
    return channel_id * THRESHOLD_LIMIT_1_5;
}

int main() {
    printf("Oil Temp: %f\n", rd_tmp(3));
    return 0;
}
