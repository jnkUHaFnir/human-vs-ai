int Add_To_Array(char Word[50]){
    int Word_Found = 0;
    
    for(int i = 0; i < Array_Index; i++) {
        if(strcmp(StructPointer[i].Word, Word) == 0) {
            StructPointer[i].Count++;
            Word_Found = 1;
            break; // Exit the loop since word is found
        }
    }

    if(Word_Found == 0) {
        strcpy(StructPointer[Array_Index].Word, Word);
        StructPointer[Array_Index].Count = 1;
        Array_Index++;
    }

    return 0;
}
