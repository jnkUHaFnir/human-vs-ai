struct x {
    int a;
    int b;
};
((1828,299),(2729,2553),(2797,2929),(2200,1383),(2894,876))
#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5];  // Assuming we know there's 5 pairs of integers in the input.
    
    // Consuming the initial '('
    getchar(); // assumes there's exactly one '(' preceding the data
    for (int i = 0; i < 5; ++i) {
        // Reading each pair into the struct members.
        // The format string skips the leading '(' and ','
        // and reads two integers separated by a ','. 
        // It also reads (and ignores) the ')' that follows each pair.
        if (scanf("(%d,%d),", &arr[i].a, &arr[i].b) != 2) {
            // Handle error: Input doesn't match expected format
            fprintf(stderr, "Error reading input\n");
            return 1;
        }
    }
    
    // Print out the values to verify they were read correctly
    for (int i = 0; i < 5; ++i) {
        printf("(%d, %d)\n", arr[i].a, arr[i].b);
    }
    
    return 0;
}
