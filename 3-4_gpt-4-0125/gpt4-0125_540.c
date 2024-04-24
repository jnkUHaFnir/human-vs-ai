#include <stdio.h>

// Define macros for each level of repetition you desire
#define REP_1 "-"
#define REP_2 REP_1 REP_1
#define REP_3 REP_2 REP_1
#define REP_4 REP_3 REP_1
#define REP_5 REP_4 REP_1
// Continue as needed

int main() {
    // Use the macros
    printf("5 hyphens: %s\n", REP_5);
    printf("3 hyphens: %s\n", REP_3);
    return 0;
}
