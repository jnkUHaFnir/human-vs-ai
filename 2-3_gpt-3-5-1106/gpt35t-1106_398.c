#include <stdio.h>
int main(){
    int counter[5];
    int i;
    for(i = 0; i < 5; i++)
        counter[i] = 0;
    printf("Please enter a string terminated by ENTER key:\n");
    char c;
    while((c = getchar()) != '\n'){
        c = tolower(c); // Convert input character to lowercase
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            for(i = 0; i < 5; i++){
                if(c == 'a' + i)
                    counter[i] = counter[i] + 1;
            }
        }
    }
    for(i = 0; i < 5; i++){
        printf("counter[%d] = %d\n", i, counter[i]);
    }
    int total_vowels = 0;
    for(i = 0; i < 5; i++){
        total_vowels += counter[i];
    }
    printf("Total number of Vowels = %d\n", total_vowels);
    return 0;
}
