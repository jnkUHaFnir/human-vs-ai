StructPointer = (struct WordElement *)malloc(Size * sizeof(struct WordElement));
if(strcmp(StructPointer[i].Word, Word)) 
if(strcmp(StructPointer[i].Word, Word) == 0)
strcpy(StructPointer[Array_Index].Word, Word);
strncpy(StructPointer[Array_Index].Word, Word, sizeof(StructPointer[Array_Index].Word));
