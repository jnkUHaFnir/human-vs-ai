int Create_Array(int Size) {
    StructPointer = (struct WordElement *) calloc(Size, sizeof(struct WordElement));
    if (StructPointer == NULL) {
        // Handle allocation failure
        return -1;
    }
    Array_Size = Size;
    return 0;
}

int Add_To_Array(char Word[50]) {
    int Word_Found = 0;
    for (int i = 0; i < Array_Index && Word_Found != 1; i++) {
        if (strcmp(StructPointer[i].Word, Word) == 0) {
            StructPointer[i].Count++;
            Word_Found = 1;
        }
    }
    if (Word_Found == 0 && Array_Index < Array_Size) {
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1;
        printf("WORD: %s\n", StructPointer[Array_Index].Word);
        Array_Index++;
    }
    return 0;
}

int Print_All(char File_Name[50]) {
    Writer = fopen(File_Name, "w");
    if (Writer == NULL) {
        // Handle file opening failure
        return -1;
    }
    printf("Printing starts now: \n");
    for (int i = 0; i < Array_Index; i++) {
        fprintf(Writer, "%s\t\t%d\n", StructPointer[i].Word, StructPointer[i].Count);
    }
    fclose(Writer);
    free(StructPointer);
    return 0;
}
