#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j=0;

    do
    {
        ++j;
        if (scanf("%d", &i) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            scanf("%*s"); // Clear the input buffer
            continue;
        }
        printf("\n\n%d %d\n\n", i, j);
    }
    while((i!=8) && (j<10));  

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int i, j=0;

    do
    {
        ++j;
        if (!(cin >> i)) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();                 // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
            continue;
        }
        cout << i << " " << j << "\n";
    }
    while((i != 8) && (j < 10));

    cout << "\nj = " << j << "\n";
    return 0;
}
