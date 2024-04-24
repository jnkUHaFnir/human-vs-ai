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

struct WordElement *StructPointer;

int Create_Array(int Size){
    StructPointer = (struct WordElement *)malloc(Size * sizeof(struct WordElement)); // Correctly allocate memory for struct array
    if (StructPointer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50]){
    int Word_Found = 0;
    for (int i = 0; i < Array_Size; i++) // Fixed the loop condition
    {
        if(strcmp(StructPointer[i].Word, Word) == 0) // Check for matching words
        {
            StructPointer[i].Count++;
            Word_Found = 1;
            break; // Exit loop once word is found
        }
    }
    if (Word_Found == 0)
    {
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1; // Initialize count for new word
        Array_Index++;
    }

    return 0;
}

int Print_All(char File_Name[50]){
    Writer = fopen(File_Name, "w");
    if (Writer == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        return -1;
    }
    for (int i = 0; i < Array_Index; i++)
    {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);
    }
    free(StructPointer);
    fclose(Writer);
    return 0;
}

int main(){
    Create_Array(100);
    Add_To_Array("this");
    Add_To_Array("document");
    Add_To_Array("contains");
    Add_To_Array("two");
    Add_To_Array("of");
    Add_To_Array("every");
    Add_To_Array("word");
    Add_To_Array("word"); // Increment count for duplicate word
    Print_All("output.txt");

    return 0;
}
