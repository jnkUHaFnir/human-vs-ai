#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {
    char *word_with_several_meanings;
    char **meanings;
    int meanings_ctr;

public:
    void word(const char* = nullptr);
    void add_meaning(char* = nullptr);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0);
    ~Expression();
};

Expression::Expression(int mctr) {
    meanings_ctr = 0;
    meanings = new char*[mctr]; // Allocating space for meanings
}

Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; i++) {
        delete[] meanings[i]; // Deleting individual meanings
    }
    delete[] meanings; // Delete the array of pointers
    delete[] word_with_several_meanings; // Deleting word
}

void Expression::word(const char* p2c) {
    if (word_with_several_meanings != nullptr) {
        delete[] word_with_several_meanings; // Delete old word if present
    }
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(char* p2c) {
    if (meanings_ctr == 0) {
        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    } else {
        char** temp_meaning = new char*[meanings_ctr];
        for(int temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
            temp_meaning[temp_ctr] = new char[strlen(meanings[temp_ctr]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[temp_ctr]);
            delete[] meanings[temp_ctr];
        }
        delete[] meanings;

        meanings = new char*[meanings_ctr];
        for(int temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
            meanings[temp_ctr] = new char[strlen(temp_meaning[temp_ctr]) + 1];
            strcpy(meanings[temp_ctr], temp_meaning[temp_ctr]);
            delete[] temp_meaning[temp_ctr];
        }
        delete[] temp_meaning;

        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    }
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
    int i;
    Expression expr;
    expr.word("bank");
    expr.add_meaning("a place to get money from");
    expr.add_meaning("a place to sit");
    expr.add_meaning("4 letter word");
    expr.add_meaning("Test meaning");
    cout << expr.get_word() << endl;

    for (i = 0; i < expr.get_total_number_of_meanings(); i++)
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
    for (i = 0; i < expr3.get_total_number_of_meanings(); i++)
        cout << " " << expr3.get_meaning(i) << endl;

    return 0;
}
