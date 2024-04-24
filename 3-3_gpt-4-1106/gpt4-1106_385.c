#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("filename.txt", "r"); // Replace filename.txt with your actual file
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char line[10]; // Increase buffer size to accommodate newline and null terminator
    int livecells;
    int alive_row, alive_column;
    
    if (fgets(line, sizeof(line), fp) != NULL) {
        livecells = atoi(line);
        fprintf(stderr, "\n%i live cells\n", livecells);
    } else {
        fprintf(stderr, "Error reading live cells count\n");
        fclose(fp);
        return 1;
    }
    
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf(line, "%d %d", &alive_row, &alive_column) == 2) {
            fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);
        } else {
            fprintf(stderr, "\n Error reading cell coordinates\n");
            break;
        }
    }

    fclose(fp);
    return 0;
}
