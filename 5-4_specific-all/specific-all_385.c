fgets(line, 2, fp);
fgets(line, 3, fp);
fgets(line, 3, fp); // Read the first line containing the number of live cells
livecells = atoi(line);
fprintf(stderr, "\n%i live cells\n", livecells);    

while (fgets(line, 5, fp) != NULL) 
{
  alive_row = atoi(&line[0]);
  alive_column = atoi(&line[2]);

  fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
}
