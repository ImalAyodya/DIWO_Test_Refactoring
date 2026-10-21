#include <stdio.h>

int validate_ota_block_size(int block_bytes) {
    if (block_bytes > 512) {
        return -1;
    }
    return block_bytes;
}

int main() {
    printf("OTA Block Status: %d\n", validate_ota_block_size(256));
    return 0;
}
