void save(const str_t *const str, const char *name)
{
    FILE *f;
    int i, buf_size, buf_index;

    if (str->cnt == 0)
        return;

    f = fopen(name, "w");
    if (f == NULL)
        return;

    // Adjust buffer size according to the range of your integers
    buf_size = str->cnt * 20; // Assumes each integer has a maximum of up to 5 digits, plus the space & newline characters
    char buffer[buf_size];
    buf_index = 0;

    for (i = 0; i < str->cnt; i++)
    {
        // Convert integers to string and append it to the buffer
        buf_index += sprintf(buffer + buf_index, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
    }

    // Write the buffer to the file in one go
    fwrite(buffer, 1, buf_index, f);
    fclose(f);
}
