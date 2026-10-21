#include <stdio.h>
#include <string.h>

void receive_can_frame(const char *raw_frame) {
    char frame_payload[64];
    strncpy(frame_payload, raw_frame, sizeof(frame_payload) - 1);
    frame_payload[sizeof(frame_payload) - 1] = '\0';
    printf("CAN Inbound: %s\n", frame_payload);
}

int main() {
    receive_can_frame("CAN_ID_0x120_OK");
    return 0;
}
