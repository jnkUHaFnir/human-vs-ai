#include <stdio.h>

#define REPEAT_DASHES(n) str_repeat("-", n)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s str_repeat(s, n-1)

#define str_repeat(s, n) s

int main() {
    printf("%s\n", REPEAT_DASHES(10)); // Output: ----------
    return 0;
}
