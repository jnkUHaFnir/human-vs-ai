#include <iostream>
#include <string>

std::string ConvertToString(int num) {
    std::string result = std::to_string(num);
    while (result.size() < 3) {
        result = "0" + result;
    }
    return result;
}

int main() {
    std::string String4H1 = "*FV";
    std::string String4H3 = "*RV";
    std::string String4H2 = "#";

    int data1 = 200;
    int data2 = 200;

    String4H1 += ConvertToString(data1);     //*FV200
    String4H3 += ConvertToString(data2);     //*RV200

    String4H1 += String4H2;   //*FV200#
    String4H3 += String4H2;   //*RV200#

    std::cout << String4H1 << std::endl;
    std::cout << String4H3 << std::endl;

    return 0;
}
