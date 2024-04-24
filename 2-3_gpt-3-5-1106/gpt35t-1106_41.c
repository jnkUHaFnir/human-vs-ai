if ((strlen(fpath) >= 4 && strcmp(fpath + strlen(fpath) - 4, ".exe") == 0) || 
    (strlen(fpath) >= 3 && strcmp(fpath + strlen(fpath) - 3, ".o") == 0))
{
    binFile = 1;
}
