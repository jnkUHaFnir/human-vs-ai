#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <fstream>

int main() {
    std::ifstream file("your_file.txt");
    rapidjson::IStreamWrapper isw(file);

    std::string line;
    while (std::getline(file, line)) {
        rapidjson::Document doc;
        doc.Parse(line.c_str());

        float x = doc[0].GetFloat();
        float y = doc[1].GetFloat();
        float z = doc[2].GetFloat();

        // do something with x, y, and z
    }
}
