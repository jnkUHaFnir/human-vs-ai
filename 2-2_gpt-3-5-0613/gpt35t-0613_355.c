#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file_name.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int first_num;
    int line = 1;

    while (!feof(file)) {
        if (line == 1) {
            fscanf(file, "%d", &first_num);
            int* p = malloc(first_num * sizeof(int));
            if (p == NULL) {
                printf("Memory allocation failure.\n");
                fclose(file);
                return 1;
            }

            int j;
            for (j = 0; j < first_num; j++) {
                fscanf(file, "%d", &p[j]);
            }

            for (j = 0; j < first_num; j++) {
                printf("%d ", p[j]);
            }
            printf("\n");

            free(p);
            line++; // Move to the next line
        }
    }

    fclose(file);
    return 0;
}
