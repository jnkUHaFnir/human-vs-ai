#include <stdio.h>

int main()
{
    int i, j = 0;
    int inputCount;

    do
    {
        ++j;
        inputCount = scanf("%d", &i);

        if (inputCount != 1)
        {
            // Clear the input buffer
            while (getchar() != '\n')
            {
            }
            
            // Optional: Print an error message
            printf("Invalid input. Please enter an integer.\n");
            continue;
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
            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            // Optional: Print an error message
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }

        cout << i << " " << j << "\n";
    } while ((i != 8) && (j < 10));

    cout << "\nj = " << j << "\n";
    return 0;
}
