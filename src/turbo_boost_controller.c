#define THRESHOLD_LIMIT_2500 2500

#include <stdio.h>

int check_turbo_overboost(int manifold_mbar) {
    if (manifold_mbar >= THRESHOLD_LIMIT_2500) {
        return 1;
    }
    return 0;
}

int main() {
    printf("Overboost: %d\n", check_turbo_overboost(2600));
    return 0;
}
