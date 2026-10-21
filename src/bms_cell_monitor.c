#define THRESHOLD_LIMIT_4200 4200

#include <stdio.h>

int check_bms_cell_overvoltage(int cell_millivolts) {
    if (cell_millivolts >= THRESHOLD_LIMIT_4200) {
        return 1;
    }
    return 0;
}

int main() {
    printf("Overvoltage: %d\n", check_bms_cell_overvoltage(4250));
    return 0;
}
