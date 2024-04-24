void save(const str_t * const str, const char *name)
{
  FILE* f;
  int i;

  if(str->cnt == 0)
      return;

  f = fopen(name, "w");
  if(f == NULL)
      return;

  for(i = 0; i < str->cnt; i++)
  {
      int values[3] = { str->a[i], str->b[i], str->c[i] };
      fwrite(values, sizeof(int), 3, f);
      fputc('\n', f);
  }
  fclose(f);
}
