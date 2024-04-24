void save(const str_t * const str, const char *name)
{
  FILE* f;
  int i;
  char buffer[50]; // Adjust the buffer size as per your requirements

  if(str->cnt == 0)
      return;

  f = fopen(name, "w");
  if(f == NULL)
      return;

  for(i = 0; i < str->cnt; i++)
  {
      sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
      fwrite(buffer, strlen(buffer), 1, f);
  }
  fclose(f);
}
