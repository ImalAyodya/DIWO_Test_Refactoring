#include <stdio.h>

void log_engine_status(int rpm, const char *mode) {
    char log_entry[128];
    sprintf(log_entry, "RPM_%d_MODE_%s", rpm, mode);
    printf("Log: %s\n", log_entry);
}

int main() {
    log_engine_status(3200, "SPORT");
    return 0;
}
