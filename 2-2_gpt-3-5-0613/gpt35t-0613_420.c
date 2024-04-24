#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(const char* string) {
    int length = strlen(string);
    char* temp = malloc((length + 1) * sizeof(char));
    int j = 0;

    for (int i = length - 1; i >= 0; i--) {
        temp[j] = string[i];
        j++;
    }
    temp[j] = '\0';  // Add null terminator to the end of the reversed string

    return temp;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char* reversed = flip_string(argv[1]);
    printf("Reversed string: %s\n", reversed);
    free(reversed);

    printf("This is the end of the program\n");

    return 0;
}
