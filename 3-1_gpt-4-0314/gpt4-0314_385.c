while (fgets(line, 5, fp) != NULL) // checks if fgets actually reads something into the line
{
  if (line[0] == ' ' || line[0] == '\n') continue; // skip empty lines

  alive_row = atoi(&line[0]);
  alive_column = atoi(&line[2]);

  fprintf(stderr, "\n Cell: (%i)(%i)", alive_row, alive_column);
}
