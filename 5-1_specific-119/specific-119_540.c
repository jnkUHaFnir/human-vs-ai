#include <stdio.h>

#define REPEAT_STRING(s, n) REPEAT_STRING_##n(s)

#define REPEAT_STRING_1(s) s
#define REPEAT_STRING_2(s) s ## s
#define REPEAT_STRING_3(s) s ## s ## s
// Add more as needed

int main() {
    const char *myString = REPEAT_STRING("-", 10);
    printf("%s\n", myString);

    return 0;
}
