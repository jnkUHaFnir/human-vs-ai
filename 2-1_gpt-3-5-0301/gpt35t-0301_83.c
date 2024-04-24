char finalString[20];

snprintf(finalString, sizeof(finalString), "*FV%03d# *RV%03d#", BUF, BUF1);
void ConvertToString(char subject[], const char insert[], int pos)
{
    sprintf(subject + pos, "%s%s", insert, subject + pos);
}
char finalString[20];

snprintf(finalString, sizeof(finalString), "*FV%d# *RV%d#", BUF, BUF1);
ConvertToString(finalString, "200", 3);
``` 
Note that you don't need to use snprintf to convert the integers to strings, you can directly use %d in sprintf.
