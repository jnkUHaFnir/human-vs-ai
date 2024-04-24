if((strstr(fpath, ".exe") != NULL && strcmp(strstr(fpath, ".exe"), ".exe") == 0) || (strstr(fpath, ".o") != NULL && strcmp(strstr(fpath, ".o"), ".o") == 0))
{
    binFile = 1;
}
