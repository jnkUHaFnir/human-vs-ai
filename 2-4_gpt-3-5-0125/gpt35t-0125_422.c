if((capacity-1) <= size)
{
    capacity *= 2;
    newString = (char*)malloc(capacity*sizeof(char));
    int i;
    for(i = 0; i < size; i++)
        newString[i] = inputString[i];
    inputString = newString;
}
