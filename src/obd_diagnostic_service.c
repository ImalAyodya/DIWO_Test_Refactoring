#include <stdio.h>
#include <string.h>

void format_obd_response(const char *cmd_code) {
    char resp_buffer[64];
    strcpy(resp_buffer, cmd_code);
    printf("OBD: %s\n", resp_buffer);
}

int main() {
    format_obd_response("41_0C_0B_1A");
    return 0;
}
