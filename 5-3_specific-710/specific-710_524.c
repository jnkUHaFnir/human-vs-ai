#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Array_Size=0;
int Array_Index=0;
FILE *Writer;
struct WordElement
{
    int Count;
    char Word[50];
};

struct WordElement *StructPointer; //just a pointer to a structure

int Create_Array(int Size){
    StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
    Array_Size = Size;

    // Initialize Count field to 0 for each struct
    for(int i = 0; i < Array_Size; i++) {
        StructPointer[i].Count = 0;
    }
    
    return 0;
}

int Add_To_Array(char Word[50]){
    int Word_Found=0;
    for(int i=0; i < Array_Size && Word_Found!=1; i++)
    {
        if(strcmp(StructPointer[i].Word, Word) == 0) // Compare for equality
        {
            StructPointer[i].Count++;
            Word_Found=1;
        }
    }
    if(Word_Found==0)
    {
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1; // Initialize the count for the new word
        printf("WORD: %s\n", StructPointer[Array_Index].Word);
        Array_Index++;
    }

    return 0;
}

int Print_All(char File_Name[50])
{
    Writer = fopen(File_Name, "w");
    printf("Printing starts now: \n");
    for(int i=0; i < Array_Size; i++)
    {
        fprintf(Writer, "%s\t\t%d\n",StructPointer[i].Word, StructPointer[i].Count);
    }
    free(StructPointer);
    return 0;
}
