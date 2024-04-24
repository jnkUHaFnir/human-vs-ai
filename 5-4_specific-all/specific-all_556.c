int Create_Array(int Size){
    StructPointer = (struct WordElement *)malloc(Size * sizeof(struct WordElement));
    if (StructPointer == NULL) {
        // Handle memory allocation failure
        return -1;
    }
    for (int i = 0; i < Size; i++) {
        StructPointer[i].Count = 0;
        memset(StructPointer[i].Word, 0, sizeof(StructPointer[i].Word)); // Initialize the Word array
    }
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50]){
    int Word_Found = 0;
    for (int i = 0; i < Array_Index && Word_Found != 1; i++) {
        if (strcmp(StructPointer[i].Word, Word) == 0) {
            StructPointer[i].Count++;
            Word_Found = 1;
        }
    }
    if (Word_Found == 0) {
        if (Array_Index < Array_Size) {
            strcpy(StructPointer[Array_Index].Word, Word);
            printf("WORD: %s\n", StructPointer[Array_Index].Word);
            StructPointer[Array_Index].Count++;
            Array_Index++;
        } else {
            // Handle array full situation
        }
    }
    return 0;
}
