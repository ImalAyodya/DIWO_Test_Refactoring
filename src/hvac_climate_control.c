#include <stdio.h>

int set_clm(int setpoint_deg_c) {
    return setpoint_deg_c + 2;
}

int main() {
    printf("Climate set: %d\n", set_clm(22));
    return 0;
}
