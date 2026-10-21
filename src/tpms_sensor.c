#include <stdio.h>

int check_tpms_nominal_psi(int measured_psi) {
    if (measured_psi < 32) {
        return 1;
    }
    return 0;
}

int main() {
    printf("TPMS Warning: %d\n", check_tpms_nominal_psi(28));
    return 0;
}
