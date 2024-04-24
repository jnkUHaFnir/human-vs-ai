int Add_To_Array(char Word[50]){
    int Word_Found = 0;
    for(int i = 0; i < Array_Index; i++) { // Change Array_Size to Array_Index
        if(strcmp(StructPointer[i].Word, Word) == 0) // Compare with 0 for a match
        {
            StructPointer[i].Count++;
            Word_Found = 1;
            break; // Exit loop once word is found
        }
    }

    if(Word_Found == 0)
    {
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1; // Initialize count for new word
        Array_Index++;
    }

    return 0;
}
