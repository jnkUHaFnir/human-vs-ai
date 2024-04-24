#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Expression {
    string word_with_several_meanings;
    vector<string> meanings;

public:
    void word(const char* p2c = NULL);
    void add_meaning(const char* p2c = NULL);
    const char* get_word();
    int get_total_number_of_meanings();
    const char* get_meaning(int meanx = 0);
};

void Expression::word(const char* p2c) {
    word_with_several_meanings = p2c;
}

void Expression::add_meaning(const char* p2c) {
    meanings.push_back(p2c);
}

const char* Expression::get_meaning(int meanx) {
    return meanings[meanx].c_str();
}

const char* Expression::get_word() {
    return word_with_several_meanings.c_str();
}

int Expression::get_total_number_of_meanings() {
    return static_cast<int>(meanings.size());
}

int main(void) {
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("b place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for (int i = 0; i < expr.get_total_number_of_meanings(); i++)
        cout << " " << expr.get_meaning(i) << endl;
    Expression expr2;
    expr2.word("class");
    expr2.add_meaning("a school class");
    expr2.add_meaning("a classification for a hotel");
    expr2.add_meaning("Starts with C");
    cout << expr2.get_word() << endl;
    for (i = 0; i < expr2.get_total_number_of_meanings(); i++)
        cout << " " << expr2.get_meaning(i) << endl;

    Expression expr3;
    expr3.word("A very long test");
    char str[] = "Meaning_    ";
    for (int kx = 0; kx < 31; kx++) {
        str[8] = ('A' + kx);
        expr3.add_meaning(str);
    }

    cout << expr3.get_word() << endl;
    for (int i = 0; i < expr3.get_total_number_of_meanings(); i++)
        cout << " " << expr3.get_meaning(i) << endl;
    return 0;
}
