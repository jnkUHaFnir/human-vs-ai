#include<vector>

int main(int argc, char * argv[]) {
    const int size = 1000000000;
    std::vector <int> b;
    b.reserve(size);
    for(int i = 0; i < size; i++) {
        b.push_back(i);
    }    

    return 0;
}
