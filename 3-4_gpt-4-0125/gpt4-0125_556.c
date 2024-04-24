StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
if(strcmp(StructPointer[i].Word, Word) == 0) // Correctly checks for an existing word
for (int i = 0; i < Array_Size && Word_Found != 1; i++)
StructPointer = (struct WordElement *) calloc(Size, sizeof(struct WordElement));
for (int i = 0; i < Size; i++) {
    StructPointer[i].Count = 0;
    StructPointer[i].Word[0] = '\0'; // Set the first char to null terminator, marking an empty string
}
if (Word_Found == 0 && Array_Index < Array_Size) { /*...*/ }
