void service_data_func(char text[])
{
    int i = 0;
    int Wstart = 0;
    int Wend = 0;
    char name[19] = {0x20};
    int len = strlen(text);
    int menunum = -1; // Initialize with -1 to indicate no struct has been assigned yet
    int menunum_charge = 0;

    while (i < len)
    {
        if (text[i] == '"' && text[i + 1] == 'i' &&
            text[i + 2] == 'd')
        {
            while (i < len)
            {
                if (text[i] == ':')
                {
                    Wstart = i + 1;
                }
                else if (text[i] == ',' || text[i] == '}')
                {
                    Wend = i;
                    strncpy(name, text + Wstart, Wend - Wstart);
                    menunum++;
                    serv_data[menunum].id = atoi(name);
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                }
                i++;
            }
        }
        else if (text[i] == 's' && text[i + 1] == 'e' &&
                 text[i + 2] == 'r' && text[i + 3] == 'v' && text[i + 4] == 'i' &&
                 text[i + 5] == 'c' && text[i + 6] == 'e' && text[i + 7] == '_' && text[i + 8]
                 == 'c' && text[i + 9] == 'h' && text[i + 10] == 'a' && text[i + 11] ==
                 'r' && text[i + 12] == 'g' && text[i + 13] == 'e' && text[i + 14] == '_' &&
                 text[i + 15] == 'l' && text[i + 16] == 'i' && text[i + 17] == 's' &&
                 text[i + 18] == 't')
        {
            while (i < len)
            {
                if (text[i] == 'f' && text[i + 1] == 'r' &&
                    text[i + 2] == 'o' && text[i + 3] == 'm')
                {
                    while (i < len)
                    {
                        if (text[i] == ':')
                        {
                            Wstart = i + 1;
                        }
                        else if (text[i] == ',' || text[i] == '}')
                        {
                            Wend = i;
                            strncpy(name, text + Wstart, Wend - Wstart);
                            serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
                            memset(name, 0, sizeof(name));
                            menunum_charge++;
                            i++;
                            break;
                        }
                        i++;
                    }
                }
                i++;
            }
        }
        i++;
    }
}

int main()
{
    service_data_func(text);
    printf("%d\n", serv_data[0].charge_arr[0].from);
    
    return 0;
}