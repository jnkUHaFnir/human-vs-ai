`
char* upcase (char *s)
{
    size_t len = strlen(s);
    if (!s)
    {
       return NULL;
    }
    for ( size_t i; i < len; i++ )
    {
        if ( s[i] >= 'a' && s[i] <= 'z' )
            s[i] -= ' ';
    }
    return s;    
}
`