#include <stdio.h>
#include <stdbool.h>

// Fixed function signature and return type to void since we're not returning any value
void enter(int MeasurementData[], int *num_measurements)
{
    int i;
    for (i = 0; i < 10; ++i)
    {
        int value;
        printf("Enter measurement %d (or enter -1 to quit): ", i + 1);
        scanf("%d", &value);

        if (value == -1)
        {
            // Exit the loop when the user enters -1
            break;
        }

        MeasurementData[i] = value;
        (*num_measurements)++;
    }
}

void view(int MeasurementData[], int num_measurements)
{
    for (int i = 0; i < num_measurements; ++i)
    {
        printf("Element %d: %d\n", i + 1, MeasurementData[i]);
    }
}

int main()
{
    int MeasurementData[10];
    int num_measurements = 0;
    char menu_option;

    while (true)
    {
        printf("Measurement tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");

        printf("Enter your option:\n");
        scanf(" %c", &menu_option);

        if (menu_option == 'e') // enter values
        {
            enter(MeasurementData, &num_measurements);
        }
        else if (menu_option == 'v') // view values
        {
            view(MeasurementData, num_measurements);
        }
        else if (menu_option == 'c')
        {
            // Compute functionality
        }
        else if (menu_option == 'r')
        {
            // Reset functionality
        }
        else if (menu_option == 'q')
        {
            printf("Exiting Measurement tool 2.0\n");
            return 0;
        }
    }
}
