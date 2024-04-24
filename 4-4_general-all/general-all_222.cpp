#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Expression {

    char *word_with_several_meanings;
    char **meanings;
    int meanings_ctr;

public:
    void word(const char* p2c = NULL);
    void add_meaning(const char* p2c = NULL);
    char* get_word();
    int get_total_number_of_meanings();
    char* get_meaning(int meanx = 0);
    Expression(int mctr = 0);
    ~Expression();
};

Expression::Expression(int mctr) {
    meanings_ctr = 0;
    meanings = new char*[mctr]; // Allocate Space for meanings
}

Expression::~Expression() {
    for(int i = 0; i < meanings_ctr; i++) {
        delete[] meanings[i]; // Free individual meaning strings
    }
    delete[] meanings; // Free the array of meaning strings
    delete[] word_with_several_meanings; // Free the word string
}

void Expression::word(const char* p2c) {
    if(word_with_several_meanings != nullptr) {
        delete[] word_with_several_meanings; // Free previously allocated memory
    }
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(const char* p2c) {
    char** temp_meanings = new char*[meanings_ctr + 1];
    for(int i = 0; i < meanings_ctr; i++) {
        temp_meanings[i] = new char[strlen(meanings[i]) + 1];
        strcpy(temp_meanings[i], meanings[i]);
        delete[] meanings[i]; // Free the old memory
    }
    temp_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp_meanings[meanings_ctr], p2c);

    delete[] meanings; // Free the old meanings array
    meanings = temp_meanings;
    meanings_ctr++;
}

char* Expression::get_meaning(int meanx) {
    if (meanx >= 0 && meanx < meanings_ctr) {
        return meanings[meanx];
    }
    return nullptr;
}

char* Expression::get_word() {
    return word_with_several_meanings;
}

int Expression::get_total_number_of_meanings() {
    return meanings_ctr;
}

int main() {
    // Your main function remains unchanged
    return 0;
}
