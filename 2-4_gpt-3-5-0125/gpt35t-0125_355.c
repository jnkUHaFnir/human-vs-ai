#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("files.txt", "r");
    int target_line = 2; // Change this to the desired line number
    int num_elements;
    
    //Skip lines until reach target_line
    for(int i = 1; i < target_line; i++){
        fscanf(file, "%*[^\n]\n"); //Skip current line
    }

    fscanf(file, "%d", &num_elements);
    
    int* p = malloc(num_elements * sizeof(int));
    
    for(int i = 0; i < num_elements; i++){
        fscanf(file, "%d", &p[i]);
    }

    for (int j = 0; j < num_elements; j++){
        printf("\t%d\t", p[j]);
    }
    
    printf("\n%d\n", num_elements);
    
    free(p);
    fclose(file);
    
    return 0;
}
