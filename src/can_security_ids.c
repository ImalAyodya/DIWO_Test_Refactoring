#include <stdio.h>

void log_security_intrusion(int arbitration_id, const char *threat) {
    char audit_str[128];
    sprintf(audit_str, "CAN_ID_%d_THREAT_%s", arbitration_id, threat);
    printf("SecAlert: %s\n", audit_str);
}

int main() {
    log_security_intrusion(512, "FRAME_INJECTION");
    return 0;
}
