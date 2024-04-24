#include <stdio.h>

#define MAX_ARRAY_SIZE 100

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Reading File\n");
    } else {
        int tek;
        int i;
        int redica[MAX_ARRAY_SIZE];
        
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            if (fscanf(myFile, "%d", &tek) == 1) {
                redica[i] = tek;
            } else {
                break;
            }
        }
        
        fclose(myFile);
    }
    
    return 0;
}
