#include <stdio.h>
#include <string.h>

int main() {
    char buf[255]="CODE=12345-MODE-12453-CODE1-12355";
    char *p = buf;
    char codeValue[6]; // Assuming the numbers have exactly 5 digits

    while ((p = strstr(p, "CODE=")) != NULL) {
        strncpy(codeValue, p+5, 5); // Copy the next 5 characters after "CODE="
        codeValue[5] = '\0'; // Null terminate the string

        printf("CODE value is: %s\n", codeValue);

        p += 5; // Move the pointer forward
    }
    
    return 0;
}
