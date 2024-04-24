#include <stdio.h>

int main() {
    int i, j=0;

    do {
        ++j;
        if (scanf("%d", &i) != 1) {
            // Clear input stream
            while(getchar() != '\n');
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }
        printf("\n\n%d %d\n\n", i, j);
    } while((i != 8) && (j < 10));  

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int i, j=0;

    do {
        ++j;
        if (!(cin >> i)) {
            // Clear input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
            continue;
        }
        cout << i << " " << j << "\n";
    } while((i != 8) && (j < 10));

    cout << "\nJ = " << j << "\n";
    return 0;
}
