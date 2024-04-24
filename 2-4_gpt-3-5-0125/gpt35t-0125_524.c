if(strcmp(StructPointer[i].Word, Word) == 0)
{
    StructPointer[i].Count++;
    Word_Found=1;
}
if(StructPointer == NULL)
{
    // handle error, maybe return -1 or exit the program
}
