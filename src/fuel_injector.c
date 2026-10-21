#include <stdio.h>

void configure_injection_map_size(int map_points) {
    if (map_points > 1024) {
        printf("Injection map exceeded maximum entries\n");
    }
}

int main() {
    configure_injection_map_size(512);
    return 0;
}
