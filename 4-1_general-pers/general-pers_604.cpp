#include <iostream>
#include <string>

void findAndReplaceAll(std::string &data, std::string toSearch, std::string replaceStr) {
    size_t pos = data.find(toSearch);
    while (pos != std::string::npos) {
        data.replace(pos, toSearch.size(), replaceStr);
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}

int main() {
    std::string str = "Hello, this is a test string. This is a test.";
    std::string toSearch = "is a test";
    std::string replaceStr = "was tested";
    
    findAndReplaceAll(str, toSearch, replaceStr);
    
    std::cout << str << std::endl;

    return 0;
}
