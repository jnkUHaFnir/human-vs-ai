symbol *temp = realloc(symbol_Table, newSize*sizeof(symbol));
if(temp != NULL)
{
  symbol_Table = temp;
}
else
{
  printf("ERROR: Couldn't realloc memory!\n");
  // handle error here
}
