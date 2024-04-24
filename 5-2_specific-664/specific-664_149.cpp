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
    void add_meaning(const char* = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(); 
    ~Expression(); 
};

Expression::Expression() {
    meanings_ctr = 0;
    meanings = nullptr;
}

Expression::~Expression() {
    delete [] word_with_several_meanings;
    for (int i = 0; i < meanings_ctr; i++) {
        delete [] meanings[i];
    }
    delete [] meanings;
}

void Expression::word(const char *p2c) {
    delete [] word_with_several_meanings;
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(const char* p2c) {
    char** temp = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; i++) {
        temp[i] = meanings[i];
    }
    temp[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp[meanings_ctr], p2c);

    delete [] meanings;
    meanings = temp;
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

    for(int i = 0; i < expr.get_total_number_of_meanings(); i++)
            cout << " " << expr.get_meaning(i)  << endl;

    // Other expressions

    return 0;
}
