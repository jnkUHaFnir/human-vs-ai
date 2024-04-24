char address[1000];

printf("Enter your address: ");
fgets(address, sizeof(address), stdin);

printf("Your address is: %s", address);
