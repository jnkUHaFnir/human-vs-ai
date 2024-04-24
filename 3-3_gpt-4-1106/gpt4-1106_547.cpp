#include <stdio.h>

int main()
{
    int i, j = 0, scanf_result;

    do
    {
        ++j;
        scanf_result = scanf("%d", &i);
        
        if (scanf_result == EOF) {
            // Handle end-of-file condition, if relevant
            break;
        } else if (scanf_result == 0) {
            // Invalid input, clear buffer
            while (getchar() != '\n') continue;
        } else {
            // Valid input
            printf("\n\n%d %d\n\n", i, j);
        }
    }
    while ((i != 8) && (j < 10));

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int i, j = 0;

    do
    {
        ++j;
        if (!(cin >> i)) {
            // Clear error state
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Valid input
            cout << i << " " << j << "\n";
        }
    }
    while ((i != 8) && (j < 10));

    cout << "\nj = " << j << "\n";
    return 0;
}
