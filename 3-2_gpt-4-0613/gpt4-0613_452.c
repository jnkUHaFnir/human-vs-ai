#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hexstr_to_bytes(const char* hexstr, unsigned char** bytes) {
    size_t len = strlen(hexstr);
    if(len % 2 != 0)
        return -1;  // Invalid hex string
    size_t byte_len = len / 2;
    *bytes = (unsigned char*)malloc(byte_len);
    for(size_t i = 0; i < len; i += 2) {
        sscanf(hexstr + i, "%2hhx", *bytes + (i / 2));
    }
    return byte_len;
}

int main(){
    FILE *f;
    long offset_ed;
    unsigned char *hexes;
    char hexesStr[100];
    long bytes_len;

    f=fopen("example.exe","rb+");

    printf("Specify offset: ");
    if(scanf("%ld", &offset_ed) != 1) {
        printf("Invalid offset\n");
        return 1;
    }
    fseek(f, offset_ed, SEEK_SET);

    printf("Specify HEX bytes to be written to the binary: ");
    if(scanf("%s", hexesStr) != 1) {
        printf("Invalid hex bytes\n");
        return 1;
    }

    if((bytes_len = hexstr_to_bytes(hexesStr, &hexes)) == -1) {
        printf("Invalid hex string\n");
        return 1;
    }

    fwrite(hexes, 1, bytes_len, f);
    
    free(hexes);
    fclose(f);
    return 0;
}
