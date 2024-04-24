#include <iostream>

int main(int argc, char * argv[]) {
    const unsigned long long size = 1000000000;
    int* a = new int[size];
    int next_power = 1;
    for (int i = 0; i < size; i++) {
        a[i] = i;
        if (i == next_power - 1) {
            next_power *= 2;
            int* temp = new int[next_power];
            std::copy(a, a + next_power / 2, temp);
            delete[] a;
            a = temp;
        }
    }
    delete[] a;
    return 0;
}
