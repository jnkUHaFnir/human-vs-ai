#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    int a = 0;
    int b = 0;
    char key;

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, " %c", &key);   // fix the sscanf format string and store result in key
        printf("zimu is: %c\n", key);

        if (key == 'a') {
            sscanf(buffer, "a=%d", &a);  // fix the sscanf function and store the result in a
        }
        if (key == 'b') {
            sscanf(buffer, "b=%d", &b);  // fix the sscanf function and store the result in b
        }
    }
    fclose(fp);  // close the file
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
