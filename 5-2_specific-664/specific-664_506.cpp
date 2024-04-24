#include <vector>

int main(int argc, char * argv[]) {
    const int size = 1000000000;
    std::vector<int> b;
  
    // Set the growth factor for the vector
    b.reserve(size * 2); // You can adjust the multiplier as needed
    
    for(int i = 0; i < size; i++) {
        b.push_back(i);
    }    

    return 0;
}
