#include <iostream>
#include <string>
#include <unordered_map>

struct Data {
    unsigned long long A;
    std::string B;
};

class Database {
private:
    std::unordered_map<unsigned long long, Data> table;

public:
    void set(unsigned long long A, const char* B) {
        table[A] = {A, B};
    }

    Data get(unsigned long long A) {
        return table[A];
    }
};

int main() {
    Database db;
    db.set(123, "example");
    std::cout << db.get(123).B << std::endl;
    return 0;
}
