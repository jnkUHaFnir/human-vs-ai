int Create_Array(int Size){
    StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
    if (StructPointer == NULL) {
        // Handle memory allocation failure
        return -1;
    }
    Array_Size = Size;
    return 0;
}
int Add_To_Array(char Word[50]){
    int Word_Found=0;
    for(int i=0; i < Array_Size; i++) { // Change i <= Array_Size to i < Array_Size
if(Word_Found==0) {
    strcpy(StructPointer[Array_Index].Word, Word);
    StructPointer[Array_Index].Count = 1; // Initialize the count
    Array_Index++;
}
