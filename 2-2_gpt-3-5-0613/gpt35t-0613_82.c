#include <iostream>
#include <string>

int main() {
    unsigned short BUF = GetWord(@FrontVIB@,0);    
    unsigned short BUF1 = GetWord(@RearVIB@,0);

    std::string String4H1 = "*FV" + std::to_string(BUF);
    std::string String4H3 = "*RV" + std::to_string(BUF1);

    std::string result = String4H3 + " " + String4H1;
    std::cout << result << std::endl;

    return 0;
}
#include <stdio.h>

int main() {
    unsigned short BUF = GetWord(@FrontVIB@,0);    
    unsigned short BUF1 = GetWord(@RearVIB@,0);

    char String4H1[10];
    char String4H3[10];

    sprintf(String4H1, "*FV%d", BUF);
    sprintf(String4H3, "*RV%d", BUF1);

    char result[20];
    sprintf(result, "%s %s", String4H3, String4H1);
    printf("%s\n", result);

    return 0;
}
