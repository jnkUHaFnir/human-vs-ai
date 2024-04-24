int Array_Size = 0;
int Array_Index = 0;
FILE *Writer;
struct WordElement
{
    int Count;
    char Word[50];
};

struct WordElement *StructPointer; // just a pointer to a structure

int Create_Array(int Size) {
    StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
    if (StructPointer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1; // indicate failure
    }
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50]) {
    int Word_Found = 0;
    for (int i = 0; i < Array_Index; i++) {
        if (strcmp(StructPointer[i].Word, Word) == 0) {
            StructPointer[i].Count++;
            Word_Found = 1;
            break;
        }
    }
    
    if (Word_Found == 0) {
        if (Array_Index < Array_Size) {
            strcpy(StructPointer[Array_Index].Word, Word);
            StructPointer[Array_Index].Count = 1;
            Array_Index++;
        } else {
            fprintf(stderr, "Array index out of bounds\n");
            return -1; // indicate failure
        }
    }

    return 0;
}

int Print_All(char File_Name[50]) {
    Writer = fopen(File_Name, "w");
    if (Writer == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return -1; // indicate failure
    }

    fprintf(Writer, "Printing starts now:\n");
    for (int i = 0; i < Array_Index; i++) {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);
    }

    free(StructPointer);
    fclose(Writer);
    return 0;
}
