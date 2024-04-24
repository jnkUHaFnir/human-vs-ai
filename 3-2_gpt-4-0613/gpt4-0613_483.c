void save(const str_t * const s, const char *name)
{
    FILE* f;
    int i;

    if(s->cnt == 0)
        return;

    f = fopen(name, "wb"); // Binary write mode
    if(f == NULL)
        return;

    for(i = 0; i < s->cnt; i++)
    {
        fwrite(&s->a[i], sizeof(int), 1, f);
        fwrite(&s->b[i], sizeof(int), 1, f);
        fwrite(&s->c[i], sizeof(int), 1, f);
    }

    fclose(f);
}
void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i, written;
    char buffer[5000000]; //Increasing this buffer size to hold all the data

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    written = 0;
    for(i = 0; i < str->cnt; i++)
    {
        written += snprintf(buffer + written, sizeof(buffer) - written, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
    }
    fwrite(buffer, sizeof(char), written, f);

    fclose(f);
}
