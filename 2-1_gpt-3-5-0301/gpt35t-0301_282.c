#include <stdio.h>
#include <string.h>

int main() {
    double value = 12345678901234.56789;
    char str[17] = {0};
    snprintf(str, 17, "%+1.10E", value);
    // Remove the decimal point if not needed
    if (strchr(str, '.') == NULL) {
        char* p = strchr(str, 'E');
        memmove(p - 1, p, strlen(p) + 1);
        *(p - 1) = *p;
        *p = '.';
    }
    printf("%s\n", str);
    return 0;
}
+1.2345678901E+13
