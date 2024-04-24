
#include <stdio.h>
#include <string.h>

void add_spaces(char *input, char *output) {
    int i;
    int j = 0;
    int i_len = strlen(input);
    for( i = 0; i < i_len; i++){
        output[j++] = input[i];
        if(i % 2 == 1 && i != i_len-1) {
            output[j++] = ' ';
        }
    }
    output[j] = '\0';
}


int main() {
    char input[] = "ABCDEFGH";
    char output[2*strlen(input)];
    add_spaces(input, output);
    printf("%s\n", output);
    return 0;
}
AB CD EF GH
