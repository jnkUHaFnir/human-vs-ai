#include <stdio.h>
#include <ctype.h>

void sanitizeData(char* data) {
    char* src = data;
    char* dest = data;
    
    while (*src) {
        if (isalnum(*src) || isspace(*src)) {
            *dest = *src;
            dest++;
        }
        src++;
    }
    
    *dest = '\0';
}

int main() {
    char data[] = "Th!is i@s a sa\nmple 123 dat#a s\ntrin@g.";
    
    // Display original data
    printf("Original data: %s\n", data);
    
    // Sanitize the data
    sanitizeData(data);
    
    // Display sanitized data
    printf("Sanitized data: %s\n", data);
    
    return 0;
}
