#define THRESHOLD_LIMIT_300 300

#include <stdio.h>

int check_auto_headlight_trigger(int lux_level) {
    if (lux_level < THRESHOLD_LIMIT_300) {
        return 1;
    }
    return 0;
}

int main() {
    printf("Headlight: %d\n", check_auto_headlight_trigger(150));
    return 0;
}
