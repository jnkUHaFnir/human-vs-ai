#define MAX_LINE_LENGTH 10 // Maximum length of each line

char line[MAX_LINE_LENGTH];
fgets(line, MAX_LINE_LENGTH, fp);
livecells = atoi(line);
fprintf(stderr, "\n%i live cells\n", livecells);    

while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) 
{
  alive_row = atoi(&line[0]);
  alive_column = atoi(&line[2]);

  fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
}
