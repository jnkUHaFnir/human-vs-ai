#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

std::string ConvertToString(char subject[], const char insert[], int pos)
{
    std::string str(subject);
    std::string ins(insert);
    str.insert(pos, ins);
    return str;
}

int main()
{    
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    char data1[10];
    char data2[10];

    snprintf(data1,4, "%03d", 200); //Convert integer to string function
    snprintf(data2,4, "%03d", 200); //Convert integer to string function

    std::string String4H1_new = ConvertToString(String4H1,data1,strlen(String4H1));   
    std::string String4H3_new = ConvertToString(String4H3,data2, strlen(String4H3)); 

    String4H1_new += String4H2; // append "String4H2" at the end of "String4H1_new"
    String4H3_new += String4H2; // append "String4H2" at the end of "String4H3_new"

    std::cout << String4H1_new.c_str() << std::endl; // *FV200#
    std::cout << String4H3_new.c_str() << std::endl; // *RV200#
}
