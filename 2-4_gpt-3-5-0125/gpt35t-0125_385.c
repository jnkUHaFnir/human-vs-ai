fgets(line, sizeof(line), fp);
livecells = atoi(line);
fprintf(stderr, "\n%i live cells\n", livecells);    

while (fgets(line, sizeof(line), fp) != NULL) 
{
    alive_row = atoi(&line[0]);
    alive_column = atoi(&line[2]);

    fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);       
}
