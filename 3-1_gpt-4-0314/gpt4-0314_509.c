#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char title[100];
    FILE *fp;
    // ... rest of the code
    fscanf(fp, "<%99s>", title);
    // ... rest of the code
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, b;
    char *title;
    FILE *fp;
    // ... rest of the code

    // Allocate memory for "title" (for example, 100 bytes)
    title = malloc(100 * sizeof(char));
    if (title == NULL)
    {
        printf("Error: Cannot allocate memory for title\n");
        fclose(fp);
        return 1;
    }
    
    fscanf(fp, "<%99s>", title);
    // ... rest of the code

    // Remember to free the allocated memory after you are done using it.
    free(title);
}
