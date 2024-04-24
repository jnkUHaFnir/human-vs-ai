#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {
    char *word_with_several_meanings;
    char **meanings;
    int meanings_ctr;

public:
    void word(const char* = NULL);
    void add_meaning(char* = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0);
    ~Expression();
};

Expression::Expression(int mctr) {
    meanings_ctr = 0;
    meanings = new char*[mctr];
}

Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; ++i) {
        delete[] meanings[i];
    }
    delete [] meanings;
    delete [] word_with_several_meanings;
}

void Expression::word(const char *p2c) {
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(char *p2c) {
    char** temp_meaning = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; ++i) {
        temp_meaning[i] = meanings[i];
    }
    temp_meaning[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp_meaning[meanings_ctr], p2c);
    
    for (int i = 0; i < meanings_ctr; ++i) {
        delete[] meanings[i];
    }
    delete[] meanings;

    meanings = temp_meaning;
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

int main(void) {
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("a place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for (int i = 0; i < expr.get_total_number_of_meanings(); i++)
        cout << " " << expr.get_meaning(i) << endl;

    // Other expressions

    return 0;
}
