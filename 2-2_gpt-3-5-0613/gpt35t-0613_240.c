void save(const str_t * const str, const char *name)
{
  FILE* f;
  int i;
  char buffer[32]; // adjust the buffer size based on the maximum number of digits

  if(str->cnt == 0)
      return;

  f = fopen(name, "wb"); // open the file in binary mode
  if(f == NULL)
      return;

  for(i = 0; i < str->cnt; i++)
  {
      // convert the integers to string using sprintf
      sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
      
      // write the string buffer to the file using fwrite
      fwrite(buffer, sizeof(char), strlen(buffer), f);
  }
  fclose(f);
}
