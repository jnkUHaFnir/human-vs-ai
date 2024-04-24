#include <stdio.h>
#include <stdlib.h>

// Function to return the name of the month based on the given month number
const char* getMonthName(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return NULL;
    }
}

int main() {
    int month;
    printf("Insert the number of the month and the program will return its name: ");
    scanf("%i", &month);

    if (month >= 1 && month <= 12) {
        const char* monthName = getMonthName(month);
        printf("The month is %s\n", monthName);
    } else {
        printf("Not a valid month number\n");
    }

    system("pause");
    return 0;
}
