#include <iostream>
#include <unordered_map>
#include <string>

typedef struct Data {
    unsigned long long A;
    char *B;
} Data;

std::unordered_map<unsigned long long, Data> dataMap;

void set(unsigned long long A, char *B) {
    Data newData;
    newData.A = A;
    newData.B = B;
    dataMap[A] = newData;
}

Data get(unsigned long long A) {
    return dataMap[A];
}

int main() {
    set(12345, "Hello");
    set(67890, "World");

    Data data1 = get(12345);
    Data data2 = get(67890);

    std::cout << "Data 1: " << data1.A << ", " << data1.B << std::endl;
    std::cout << "Data 2: " << data2.A << ", " << data2.B << std::endl;

    return 0;
}
