#include<stdio.h>
int main()
{
    int i, j=0;

    do
    {
        ++j;
        if(scanf("%d", &i) != 1) {
            // handle input mismatch
            printf("Invalid input. Please enter an integer.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }
        printf("\n\n%d %d\n\n", i, j);
    }
    while((i!=8) && (j<10));  

    printf("\nJ = %d\n", j);
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int i, j=0;

    do
    {
        ++j;
        if(!(cin >> i)) {
            // handle input mismatch
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); // clear error flags
            cin.ignore(10000, '\n'); // clear input buffer
            continue;
        }
        cout << i << " " << j << "\n";
    }
    while((i!=8) && (j<10));

    cout << "\nj = " << j << "\n";
    return 0;
}
