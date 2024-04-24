#include <iostream>
#include <unordered_map>
#include <string>

struct Data {
    unsigned long long A;
    std::string B;
};

class HashTable {
private:
    std::unordered_map<unsigned long long, Data> table;

public:
    void set(unsigned long long A, const char* B) {
        table[A] = {A, B};
    }

    Data get(unsigned long long A) {
        if (table.find(A) != table.end()) {
            return table[A];
        }
        // Handle error case if key A is not found
        return {0, ""};
    }
};

int main() {
    HashTable ht;

    // Test set and get operations
    ht.set(123456789, "Hello");
    Data result = ht.get(123456789);
    std::cout << "A: " << result.A << ", B: " << result.B << std::endl;

    return 0;
}
