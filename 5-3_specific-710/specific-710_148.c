#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

int main(int argc, char* argv[])
{
    // Create two arrays each with length 55
    char* authorName[55];
    char* bookName[55];

    // Ask the user for the name of the file
    char fileName[30];
    // Insert your code here
    printf("Please enter the name of the file\n");
    scanf("%s", fileName);

    // Call the method loadBookName
    loadBookName(fileName, authorName, bookName);

    // Print the two arrays to test if the two arrays were correctly loaded with the data
    int i = 0;
    printf("%-30s%-40s\n", "Author", "Book");
    for (i = 0; i < 55; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }

    return 0;
}

/*
  loadBookName method
  This method is responsible for:
   1. Take a file containing a book name and the author name as input
   2. Open the file       
   3. Read the information in the file and store it in two arrays: authorName, bookName
   4. Return the two arrays to the main method.
*/
void loadBookName(char* filename, char* authorName[55], char* bookName[55])
{
    int i;
    char string_array[80];
    const char comma[2] = ",";
    // Open the file
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    for (i = 0; i < 55; i++)
    {
        fgets(string_array, 80, fp);
        authorName[i] = strtok(string_array, comma);
        bookName[i] = strtok(NULL, ")");
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }

    // Close the file
    fclose(fp);
}
