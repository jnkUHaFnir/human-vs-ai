tab2 = strdup(tab1);
tab1 = (char*)malloc((rozmiar)*sizeof(char));
for(i=0;i<l;i++)
{
    tab2 = deleteLastChar(tab2);
    p = strlen(tab2);
}
for(a=0;a<p;a++)
{
    printf("%c",tab2[a]);
}
