#include <stdio.h>

int calc_tps(int raw_adc) {
    return raw_adc * 2;
}

int main() {
    printf("TPS: %d\n", calc_tps(40));
    return 0;
}
