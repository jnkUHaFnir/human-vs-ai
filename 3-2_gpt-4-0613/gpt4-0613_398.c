#include <stdio.h>

int main(){
    int counter[5];
    int c, i;
    for(i = 0; i < 5; i++)
        counter[i] = 0;
    printf("Please enter a string terminated by ENTER key:\n");
    while((c = getchar()) != '\n') 
    {
        if((c == 'a' || c == 'A'))
            counter[0]++;
        else if((c == 'e' || c == 'E'))
            counter[1]++;
        else if((c == 'i' || c == 'I'))
            counter[2]++;
        else if((c == 'o' || c == 'O'))
            counter[3]++;
        else if((c == 'u' || c == 'U'))
            counter[4]++;
    }
    int total_vowels = 0;
    for(i = 0; i < 5; i++) 
    {
        printf("counter[%d] = %d\n", i, counter[i]);
        total_vowels += counter[i];
    }
    printf("Total number of vowels= %d\n", total_vowels);
    return 0; 
}
