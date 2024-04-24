#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void parse_line(const char *line, float &x, float &y, float &z) {
    char *line_copy = new char[strlen(line) + 1];
    strcpy(line_copy, line);

    char *token = strtok(line_copy, " ");
    x = atof(token);
    token = strtok(NULL, " ");
    y = atof(token);
    token = strtok(NULL, " ");
    z = atof(token);

    delete[] line_copy;
}

int main() {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    float x, y, z;
    while (std::getline(file, line)) {
        parse_line(line.c_str(), x, y, z);
        std::cout << x << " " << y << " " << z << std::endl;
    }

    file.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>

void parse_line(const std::string &line, float &x, float &y, float &z) {
    std::stringstream ss(line);
    ss >> x >> y >> z;
}

int main() {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    float x, y, z;
    while (std::getline(file, line)) {
        parse_line(line, x, y, z);
        std::cout << x << " " << y << " " << z << std::endl;
    }

    file.close();
    return 0;
}
