#include <iostream>
#include <unordered_map>
#include <string>

class BigHash {
public:
    void set(unsigned long long A, const std::string& B) {
        table[A] = B;
    }

    std::string get(unsigned long long A) {
        auto it = table.find(A);
        if (it != table.end()) {
            return it->second;
        }
        return ""; // Return an empty string if not found
    }

private:
    std::unordered_map<unsigned long long, std::string> table;
};

int main() {
    BigHash hash;

    hash.set(123456789, "Example");
    std::cout << "Get: " << hash.get(123456789) << std::endl; // Should print "Example"

    return 0;
}
