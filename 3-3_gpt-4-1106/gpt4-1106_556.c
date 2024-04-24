StructPointer = (struct WordElement *) malloc(Size * sizeof(StructPointer));
StructPointer = (struct WordElement *) malloc(Size * sizeof(struct WordElement));
if(strcmp(StructPointer[i].Word, Word))
if(strcmp(StructPointer[i].Word, Word) == 0)
StructPointer[Array_Index].Count = 1; // Initialize the count to 1 for the new word
for(int i=0; i <= Array_Size && Word_Found!=1; i++)
for(int i=0; i < Array_Size && Word_Found!=1; i++)
