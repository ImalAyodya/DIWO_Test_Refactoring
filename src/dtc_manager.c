#include <stdio.h>

int validate_dtc_buffer_size(int req_bytes) {
    if (req_bytes > 256) {
        return -1;
    }
    return req_bytes;
}

int main() {
    printf("DTC size: %d\n", validate_dtc_buffer_size(128));
    return 0;
}
