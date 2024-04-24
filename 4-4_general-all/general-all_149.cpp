#include <iostream>
#include <cstring>
using namespace std;

class Expression {
    char* word_with_several_meanings;
    char** meanings;
    int meanings_ctr;

public:
    Expression(int mctr = 1);
    ~Expression();
    void word(const char* p2c = nullptr);
    void add_meaning(const char* p2c = nullptr);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
};

Expression::Expression(int mctr) {
    meanings_ctr = 0;
    meanings = new char*[mctr];
    for (int i = 0; i < mctr; i++) {
        meanings[i] = nullptr;
    }
    word_with_several_meanings = nullptr;
}

Expression::~Expression() {
    delete[] word_with_several_meanings;

    for (int i = 0; i < meanings_ctr; i++) {
        delete[] meanings[i];
    }
    delete[] meanings;
}

void Expression::word(const char* p2c) {
    delete[] word_with_several_meanings;
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(const char* p2c) {
    char** temp_meanings = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; ++i) {
        temp_meanings[i] = meanings[i];
    }
    temp_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp_meanings[meanings_ctr], p2c);

    delete[] meanings;
    meanings = temp_meanings;

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
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");

    cout << expr.get_word() << endl;
    for (int i = 0; i < expr.get_total_number_of_meanings(); i++) {
        cout << " " << expr.get_meaning(i) << endl;
    }

    Expression expr2;
    expr2.word("class");
    expr2.add_meaning("a school class");
    expr2.add_meaning("a classification for a hotel");
    expr2.add_meaning("Starts with C");

    cout << expr2.get_word() << endl;
    for (int i = 0; i < expr2.get_total_number_of_meanings(); i++) {
        cout << " " << expr2.get_meaning(i) << endl;
    }

    Expression expr3;
    expr3.word("A very long test");
    char str[] = "Meaning_    ";
    for (int kx = 0; kx < 31; kx++) {
        str[8] = ('A' + kx);
        expr3.add_meaning(str);
    }

    cout << expr3.get_word() << endl;
    for (int i = 0; i < expr3.get_total_number_of_meanings(); i++) {
        cout << " " << expr3.get_meaning(i) << endl;
    }

    return 0;
}
