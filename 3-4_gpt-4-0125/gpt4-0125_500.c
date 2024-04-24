#include <stdio.h>
#include <ctype.h>
// Other necessary includes

void strtoupper(char *str) {
    while(*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

int main() {
    char input1[255], input2[255];
    // Assuming title and author are FILE* set up previously in your code
    fgets(input1,254,title);
    fgets(input2,254,author);
    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    strtoupper(input1);
    strtoupper(input2);

    printf("<%s> <%s>\n",input1,input2);

    return 0;
}
