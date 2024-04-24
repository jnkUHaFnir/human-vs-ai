int main()
{    
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    unsigned short BUF = GetWord(@FrontVIB@, 0);
    unsigned short BUF1 = GetWord(@RearVIB@, 0);

    char data1[10];
    char data2[10];

    snprintf(data1, 4, "%03d", BUF); 
    snprintf(data2, 4, "%03d", BUF);

    ConvertToString(String4H1, data1, 3);     
    ConvertToString(String4H3, data2, 3);     

    ConvertToString(String4H1, String4H2, 6);   
    ConvertToString(String4H3, String4H2, 6);   

    // Display String4H1 and String4H3 
}

void ConvertToString(char subject[], const char insert[], int pos) 
{
    char buf[100] = {};  
    strncpy(buf, subject, pos);               
    int len = strlen(buf);
    strcpy(buf + len, insert);                 
    len += strlen(insert);                  
    strcpy(buf + len, subject + pos);          

    strcpy(subject, buf);                 
}
