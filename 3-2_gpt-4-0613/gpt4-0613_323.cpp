#include <iostream>
#include <string>
#include <fstream>

int main()
{
    char buf[100];
    int a = 123;
    float b = 456.789f;

    std::snprintf(buf, sizeof(buf), "a = %d, b = %f", a, b);
    std::string str = buf;

    std::ofstream file{"file.txt"};
    file << str;
}
