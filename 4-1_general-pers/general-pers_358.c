#include <stdio.h>

int main() {
    int i = 0, j = 0;
    char array[1000];

    printf("Input letters to convert into integers: ");
    do {
        scanf(" %c", &array[i]);
        i++;
    } while(array[i-1] != '\n');

    for(j = 0; j < i-1; j++) {
        if(array[j] >= 'A' && array[j] <= 'Z') {
            int num = array[j] - 'A' + 1;
            printf("%d ", num);
        }
    }

    return 0;
}
