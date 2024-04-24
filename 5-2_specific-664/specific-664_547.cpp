#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j = 0;

    do {
        ++j;
        if (scanf("%d", &i) != 1) {
            printf("Invalid input. Clearing input stream.\n");
            while(getchar() != '\n'); // Clear the input stream
        } else {
            printf("\n%d %d\n", i, j);
        }
    } while ((i != 8) && (j < 10));

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int i, j = 0;

    do {
        ++j;
        if (!(cin >> i)) {
            cout << "Invalid input. Clearing input stream." << endl;
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        } else {
            cout << i << " " << j << endl;
        }
    } while ((i != 8) && (j < 10));

    cout << "\nj = " << j << endl;
    return 0;
}
