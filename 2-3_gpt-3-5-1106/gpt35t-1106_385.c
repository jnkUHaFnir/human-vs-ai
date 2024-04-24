fgets(line, 6, fp); // Increase the size of the array to account for newline
line[strcspn(line, "\n")] = 0; // Remove the newline character

livecells = atoi(line);
fprintf(stderr, "\n%i live cells\n", livecells);    

while (fgets(line, sizeof(line), fp)) 
{
  line[strcspn(line, "\n")] = 0; // Remove the newline character

  alive_row = atoi(&line[0]);
  alive_column = atoi(&line[2]);

  fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
}
