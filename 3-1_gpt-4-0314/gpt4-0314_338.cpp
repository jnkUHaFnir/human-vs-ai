#include <unordered_map>
#include <string>

std::unordered_map<unsigned long long, std::string> hashmap;

void set(unsigned long long A, const char* B) {
    hashmap[A] = std::string(B);
}

const char* get(unsigned long long A) {
    auto it = hashmap.find(A);
    if (it != hashmap.end()) {
        return it->second.c_str();
    }
    return nullptr;
}
