#include <iostream>
#include <cstring>

class Expression {
private:
    char *word_with_several_meanings;
    char **meanings;
    int meanings_ctr;

public:
    Expression();
    ~Expression();
    void word(const char* p2c);
    void add_meaning(const char* p2c);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx);
};

Expression::Expression() : word_with_several_meanings(nullptr), meanings(nullptr), meanings_ctr(0) {}

Expression::~Expression() {
    delete[] word_with_several_meanings;
    if (meanings != nullptr) {
        for (int i = 0; i < meanings_ctr; ++i) {
            delete[] meanings[i];
        }
        delete[] meanings;
    }
}

void Expression::word(const char* p2c) {
    delete[] word_with_several_meanings;
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(const char* p2c) {
    char** temp = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; ++i) {
        temp[i] = meanings[i];
    }
    temp[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp[meanings_ctr], p2c);

    delete[] meanings;
    meanings = temp;
    meanings_ctr++;
}

char* Expression::get_word() {
    return word_with_several_meanings;
}

int Expression::get_total_number_of_meanings() {
    return meanings_ctr;
}

char* Expression::get_meaning(int meanx) {
    if (meanx >= 0 && meanx < meanings_ctr) {
        return meanings[meanx];
    }
    return nullptr;
}

int main() {
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("a place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");

    std::cout << expr.get_word() << std::endl;
    for (int i = 0; i < expr.get_total_number_of_meanings(); i++) {
        std::cout << " " << expr.get_meaning(i) << std::endl;
    }

    // Additional testing and usage of the class
    // Remember to always delete objects you create to avoid memory leaks

    return 0;
}
