int max_array_size = 10;
struct WordElement *StructPointer; // just a pointer to a structure
int Array_Size = 0;

int Create_Array(int Size){
    StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
    max_array_size = Size;
    return 0;
}

int Add_To_Array(char Word[50]){
    int Word_Found=0;
    for(int i=0; i < Array_Size && Word_Found!=1; i++)
    {
        if(strcmp(StructPointer[i].Word, Word) == 0) 
        {
            StructPointer[i].Count++;
            Word_Found=1;
        }
    }
    if(Word_Found==0) // if the above if statement doesn't evaluate, this should run 
    {
        // Check if the array is full, if so, increase its size
        if (Array_Size == max_array_size) {
            max_array_size *= 2;
            StructPointer = realloc(StructPointer, max_array_size * sizeof(struct WordElement));
        }
        
        strcpy(StructPointer[Array_Size].Word, Word); // copying the word passed by the main function to the struct array at a specific index
        StructPointer[Array_Size].Word[strlen(Word)] = '\0'; // Add null-termination character
        StructPointer[Array_Size].Count = 1; // Set the count to 1 for the new word
        printf("WORD: %s\n", StructPointer[Array_Size].Word); 
        Array_Size++;
    }

    return 0;
}

int Print_All(char File_Name[50])
{
    Writer = fopen(File_Name, "w");
    printf("Printing starts now: \n");
    for(int i=0; i < Array_Size; i++)
    {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);
    }
    free(StructPointer);
    return 0;
}
