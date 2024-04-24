#include <stdio.h>
#include <stdlib.h>

int main() {
    char *directions[3];
    int i;
    for(i=0;i<3;i++){
        directions[i] = malloc(50 * sizeof(char));  // allocate memory
        printf("Enter direction %d: ", i+1);
        scanf("%s",directions[i]);
    }
    for(i=0;i<3;i++){
        printf("%s\n",directions[i]);
    }
    // Don't forget to free the allocated memory
    for(i=0;i<3;i++){
        free(directions[i]);
    }
    return 0;
}
