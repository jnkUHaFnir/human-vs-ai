void init_chars (char *arg)
{
    arg = malloc (sizeof (char)*10);
    strcpy(arg, "0123456789");
    printf ("%s\n", arg);
}
