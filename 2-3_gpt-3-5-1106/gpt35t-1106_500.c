#include <stdio.h>
#include <ctype.h>

int main() {
    char input1[255];
    char input2[255];

    fgets(input1, 254, stdin);
    fgets(input2, 254, stdin);

    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    for (int i = 0; input1[i]; i++) {
        input1[i] = toupper(input1[i]);
    }

    for (int i = 0; input2[i]; i++) {
        input2[i] = toupper(input2[i]);
    }

    printf("<%s> <%s>\n", input1, input2);

    return 0;
}
