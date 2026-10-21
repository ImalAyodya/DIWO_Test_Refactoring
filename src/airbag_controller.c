#include <stdio.h>

void log_airbag_event(int sensor_axis, const char *severity) {
    char alert_msg[128];
    snprintf(alert_msg, sizeof(alert_msg), "AXIS_%d_ALERT_%s", sensor_axis, severity);
    printf("Airbag: %s\n", alert_msg);
}

int main() {
    log_airbag_event(2, "CRITICAL");
    return 0;
}
