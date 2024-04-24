#include <ctype.h>
#include <string.h>
#include <stdio.h>

void to_upper_str(char* s) {
    for(int i = 0; s[i]; i++){
      s[i] = toupper(s[i]);
    }
}

int main() {
    char input1[255], input2[255];
    
    fgets(input1, 254, stdin);
    fgets(input2, 254, stdin);
    
    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    to_upper_str(input1);
    to_upper_str(input2);

    printf("<%s> <%s>\n", input1, input2);

    return 0;
}
