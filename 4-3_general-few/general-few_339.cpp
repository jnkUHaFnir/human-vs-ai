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
        } else {
            // Assuming a default value if not found
            return {0, "Not found"};
        }
    }
};

int main() {
    HashTable ht;
    ht.set(123456789, "Hello");
    
    unsigned long long key = 123456789;
    Data result = ht.get(key);
    std::cout << "A: " << result.A << ", B: " << result.B << std::endl;

    return 0;
}
