#include <stdlib.h>

int main()
{
    return system("which Rscript");
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char path[1035];

    /* Open the command for reading */
    FILE *fp = popen("which Rscript", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output a line at a time - output it */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    /* close */
    pclose(fp);

    return 0;
}
