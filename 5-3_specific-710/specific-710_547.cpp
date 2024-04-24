#include <stdio.h>
int main()
{
    int i, j = 0;

    do
    {
        ++j;
        if (scanf("%d", &i) != 1)
        {
            getchar(); // Clear the input buffer
            continue;  // Skip to the next iteration
        }
        printf("\n\n%d %d\n\n", i, j);
    } while ((i != 8) && (j < 10));

    printf("\nJ = %d\n", j);
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int i, j = 0;

    do
    {
        ++j;
        if (!(cin >> i))
        {
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            continue;     // Skip to the next iteration
        }
        cout << i << " " << j << "\n";
    } while ((i != 8) && (j < 10));

    cout << "\nj = " << j << "\n";
    return 0;
}
