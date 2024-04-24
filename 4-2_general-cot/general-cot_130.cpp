#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

bool isPositiveInteger(const string &s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '+'))) {
        return false;
    }

    char *p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    string input = argv[1];

    if (!isPositiveInteger(input) || stoi(input) <= 0) {
        cerr << "ERROR: Input is not a positive integer" << endl;
        return 1;
    }

    // Proceed with the program logic
    int num = stoi(input);
    cout << "Valid input: " << num << endl;

    return 0;
}
