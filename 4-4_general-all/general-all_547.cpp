#include <stdio.h>

int main() {
    int i, j = 0;

    do {
        ++j;
        if (scanf("%d", &i) != 1) {
            scanf("%*s"); // Read and discard non-integer input
            continue; // Skip current iteration
        }
        printf("\n\n%d %d\n\n", i, j);
    } while ((i != 8) && (j < 10));

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int i, j = 0;

    do {
        ++j;
        if (!(cin >> i)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard non-integer input
            continue; // Skip current iteration
        }
        cout << i << " " << j << endl;
    } while ((i != 8) && (j < 10));

    cout << "\nj = " << j << endl;
    return 0;
}
