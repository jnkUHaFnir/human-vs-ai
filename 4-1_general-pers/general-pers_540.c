#include <stdio.h>

// Define macro to repeat a string n times
#define REPEAT_STRING(string, n) REPEATED_ ## string ## _ ## n

#define REPEATED_STRING(s) #s
#define REPEATED_1_string REPEATED_STRING(-)
#define REPEATED_2_string REPEATED_1_string REPEATED_1_string
#define REPEATED_3_string REPEATED_2_string REPEATED_1_string
// Add more REPEATED_X_string definitions as needed

int main() {
    printf("%s\n", REPEAT_STRING(string, 5));
    return 0;
}
