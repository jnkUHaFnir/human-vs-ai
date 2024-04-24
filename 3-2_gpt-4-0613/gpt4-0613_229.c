#include <stdio.h>

int main() {
    char *s = "This is a test";
    char newstring[50];
    int i = 0, j = 0;

    while(s[i] != '\0'){
        if(s[i] == 't' && s[i+1] == 'e'){
            newstring[j] = 'g';
            i++;
        } else if(s[i] == 'e' && s[i+1] == 's') {
            newstring[j] = 'h';
            i++;
        } else if(s[i] == 's' && s[i+1] == 't'){
            i+=2;   // we advance 2 positions because 'st' is replaced by 'st' which consists of two characters
            newstring[j] = 'o';
            newstring[j+1] = 's';
            j++;
        } else {
            newstring[j] = s[i];
        }
        i++;
        j++;
    }
    newstring[j] = '\0';  // close the string
    printf("%s", newstring);

    return 0;
}
