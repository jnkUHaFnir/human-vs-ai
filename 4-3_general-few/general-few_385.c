fgets(line, 2, fp);
livecells = atoi(line);
fprintf(stderr, "%i live cells\n", livecells);    

while (fgets(line, 5, fp) != NULL) 
{
  alive_row = atoi(&line[0]);
  alive_column = atoi(&line[2]);

  fprintf(stderr, "Cell: (%i)(%i)\n", alive_row, alive_column);       
}
