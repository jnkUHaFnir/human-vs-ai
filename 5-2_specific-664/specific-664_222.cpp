#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {
    char* word_with_several_meanings;
    char** meanings;
    int meanings_ctr;

public:
    void word(const char* p2c = nullptr);
    void add_meaning(const char* p2c = nullptr);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0);
    ~Expression();
};

Expression::Expression(int mctr) {
    meanings_ctr = mctr > 0 ? mctr : 0;
    meanings = new char*[meanings_ctr];
}

Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; ++i) {
        delete[] meanings[i];
    }
    delete[] meanings;
    delete[] word_with_several_meanings;
}

void Expression::word(const char* p2c) {
    delete[] word_with_several_meanings;
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(const char* p2c) {
    char** new_meanings = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; i++) {
        new_meanings[i] = new char[strlen(meanings[i]) + 1];
        strcpy(new_meanings[i], meanings[i]);
        delete[] meanings[i];
    }
    new_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(new_meanings[meanings_ctr], p2c);
    
    delete[] meanings;
    meanings = new_meanings;
    meanings_ctr++;
}

char* Expression::get_meaning(int meanx) {
    return meanings[meanx];
}

char* Expression::get_word() {
    return word_with_several_meanings;
}

int Expression::get_total_number_of_meanings() {
    return meanings_ctr;
}

int main() {
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("a place to sit");
    
    cout << expr.get_word() << endl;
    for (int i = 0; i < expr.get_total_number_of_meanings(); i++) {
        cout << " " << expr.get_meaning(i) << endl;
    }

    // Add more test cases if needed

    return 0;
}
