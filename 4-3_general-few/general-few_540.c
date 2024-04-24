#include <stdio.h>

#define REPEAT_CHAR(n, c) REPEAT_CHAR_(n, c)
#define REPEAT_CHAR_(n, c) REPEAT_CHAR__(n, c)
#define REPEAT_CHAR__(n, c) REPEAT_CHAR___(n, c)
#define REPEAT_CHAR___(n, c) REPEAT_CHAR_##c

#define REPEAT_CHAR_HASH(c) ------------------


int main() {
    printf("%s\n", REPEAT_CHAR_HASH(-));
    return 0;
}
