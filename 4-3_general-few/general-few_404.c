char address[1000];

printf("Enter your address: ");
scanf(" %[^\n]", address); // Note the space before %[^\n]

printf("Your address is: %s", address);
