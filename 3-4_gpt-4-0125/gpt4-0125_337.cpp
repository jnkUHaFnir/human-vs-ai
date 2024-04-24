#include <iostream>
#include <unordered_map>
#include <string>

class DataStore {
public:
    void set(unsigned long long A, const char* B) {
        storage[A] = B;
    }

    const char* get(unsigned long long A) {
        auto it = storage.find(A);
        if (it != storage.end()) {
            return it->second.c_str();
        } else {
            return nullptr; // or whatever signifies a fail/empty value in your context
        }
    }

private:
    std::unordered_map<unsigned long long, std::string> storage;
};

int main() {
    DataStore ds;
    ds.set(123456789, "example1");
    ds.set(987654321, "example2");

    std::cout << "Getting key 123456789: " << (ds.get(123456789) ? ds.get(123456789) : "Not Found") << std::endl;
    std::cout << "Getting key 987654321: " << (ds.get(987654321) ? ds.get(987654321) : "Not Found") << std::endl;
    std::cout << "Getting key 111111111: " << (ds.get(111111111) ? ds.get(111111111) : "Not Found") << std::endl;

    return 0;
}
