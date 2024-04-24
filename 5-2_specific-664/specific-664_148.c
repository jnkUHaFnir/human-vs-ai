#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

int main(int argc, char* argv[])
{
  //Create two arrays each with length 55
  char* authorName[55];
  char* bookName[55];

  //Ask the user for the name of the file
  char fileName[30];
  printf("Please enter the name of the file\n");
  scanf("%s", fileName);

  //Call the method loadBookName
  loadBookName(fileName, authorName, bookName);

  //Print the two arrays to test if the two arrays were correctly loaded with the data
  int i = 0;
  printf("%-30s%-40s\n", "Author", "Book");
  for (i = 0; i < 55; i++) {
      printf("%-30s%-40s\n", authorName[i], bookName[i]);
  }

  return 0;
}

void loadBookName(char* filename, char* authorName[55], char* bookName[55])
{
    int i;
    char string_array[80];
    const char comma[2] = ",";

    //Open the file
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

        // Tokenize the string based on comma
        char* token = strtok(string_array, comma);
        authorName[i] = strdup(token); // Duplicate the string for author name

        // Move to the next token
        token = strtok(NULL, comma);
        if (token != NULL) {
            // Check if there is a title in the line
            bookName[i] = strdup(token); // Duplicate the string for book title
        } else {
            // Handle case where there might not be a title
            bookName[i] = strdup("");
        }
    }

    //Close the file
    fclose(fp);
}
