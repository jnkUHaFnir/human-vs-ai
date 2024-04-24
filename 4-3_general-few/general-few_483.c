void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    char buffer[512];  // Adjust the buffer size as needed

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    setvbuf(f, buffer, _IOFBF, sizeof(buffer));

    for(i = 0; i < str->cnt; i++)
    {
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fputs(buffer, f);
    }

    fclose(f);
}
