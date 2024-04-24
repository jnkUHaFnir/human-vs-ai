char buffer[10];
scanf("%s", buffer); // If the user enters more than 10 characters, buffer overflow occurs.
int num;
scanf("%d", &num); // If the user enters a character instead of a number, it fails to read and leaves num unchanged.
int num;
scanf("%d", &num); // If the user enters "abc" instead of a number, it fails to convert and leaves num unchanged.
