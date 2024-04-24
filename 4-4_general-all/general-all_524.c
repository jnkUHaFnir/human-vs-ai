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

struct WordElement *StructPointer = NULL; // Initialize to NULL

int Create_Array(int Size)
{
    StructPointer = (struct WordElement *)malloc(Size * sizeof(struct WordElement)); // Use the correct sizeof
    if (StructPointer == NULL)
    {
        // Memory allocation failed
        return -1;
    }
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50])
{
    int Word_Found = 0;
    for (int i = 0; i < Array_Index; i++) // Fix the loop condition
    {
        if (strcmp(StructPointer[i].Word, Word) == 0) // Compare if strings are equal
        {
            StructPointer[i].Count++;
            Word_Found = 1;
            break; // Exit loop if word is found
        }
    }

    if (Word_Found == 0)
    {
        if (Array_Index >= Array_Size)
        {
            // Reached the maximum array size
            return -1;
        }
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1;
        Array_Index++;
    }

    return 0;
}

int Print_All(char File_Name[50])
{
    Writer = fopen(File_Name, "w");
    printf("Printing starts now: \n");
    for (int i = 0; i < Array_Index; i++) // Loop until Array_Index
    {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);
    }
    free(StructPointer);
    return 0;
}

