#include <iostream>
#include <string>
#include <unordered_map>

struct Data {
    unsigned long long A;
    std::string B;
};

std::unordered_map<unsigned long long, Data> dataMap;

void set(unsigned long long A, char *B) {
    std::string strB(B);
    Data newData = {A, strB};
    dataMap[A] = newData;
}

Data get(unsigned long long A) {
    if (dataMap.find(A) != dataMap.end()) {
        return dataMap[A];
    } else {
        // Return some default value or handle error as needed
        std::cerr << "Data with key " << A << " not found." << std::endl;
        return {0, ""};
    }
}

int main() {
    // Example usage
    set(123456, "random_string");
    Data retrievedData = get(123456);
    std::cout << "Retrieved data: A = " << retrievedData.A << ", B = " << retrievedData.B << std::endl;

    return 0;
}
