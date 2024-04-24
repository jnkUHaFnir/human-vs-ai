char buffer[10];
scanf("%s", buffer); // Unsafe if input exceeds 9 characters (+1 for the '\0')
scanf("%9s", buffer);
