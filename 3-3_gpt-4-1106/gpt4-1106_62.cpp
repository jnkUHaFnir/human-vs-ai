#include <vector>
// ...

class Expression {
    // ...
    vector<char*> meanings;
    // ...
};

void Expression::add_meaning(const char *p2c) {
    char *new_meaning = new char[strlen(p2c) + 1];
    strcpy(new_meaning, p2c);
    meanings.push_back(new_meaning);
}

Expression::~Expression() {
    delete [] word_with_several_meanings;
    for (auto meaning : meanings) {
        delete [] meaning;
    }
}
