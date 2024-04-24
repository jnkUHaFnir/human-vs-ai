fscanf(stdin, "%d", &livecells);
fprintf(stderr, "\n%i live cells\n", livecells);    

for (int i = 0; i < livecells; i++) 
{
  if (fscanf(stdin, "%d%d", &alive_row, &alive_column) == 2)
  {
    fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);
  } 
  else 
  {
    fprintf(stderr, "\nError reading cell");
    break;
  }  
}
