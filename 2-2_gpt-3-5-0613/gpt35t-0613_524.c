#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Array_Size = 0;
int Array_Index = 0;
FILE *Writer;

struct WordElement
{
    int Count;
    char Word[50];
};

struct WordElement *StructPointer; //just a pointer to a structure

int Create_Array(int Size)
{
    StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50])
{
    int Word_Found = 0;
    for (int i = 0; i < Array_Size && Word_Found != 1; i++)
    {
        if (strcmp(StructPointer[i].Word, Word) == 0) // This should only run if the word exists in struct array
        {
            StructPointer[i].Count++;
            Word_Found = 1;
        }

    }
    if (Word_Found == 0) // if the above if statement doesn't evaluate, this should run
    {
        strcpy(StructPointer[Array_Index].Word, Word); //copying the word passed by the main function to the struct array at a specific index
        printf("WORD: %s\n", StructPointer[Array_Index].Word); // printing it just to make sure it got copied correctly
        Array_Index++;
    }

    return 0;
}

int Print_All(char File_Name[50])
{
    Writer = fopen(File_Name, "w");
    printf("Printing starts now: \n");
    for (int i = 0; i < Array_Size; i++)
    {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);

    }
    free(StructPointer);
    return 0;
}

int main() {
    // Initialize the array and add elements
    Create_Array(10);
    Add_To_Array("word1");
    Add_To_Array("word2");
    Add_To_Array("word1");

    // Print the array
    Print_All("output.txt");

    return 0;
}
