if (scount == 0)
{
    s = (students*)malloc(sizeof(students));
}
else
{
    s = realloc(s, sizeof(students) * scount);
}
getchar();
