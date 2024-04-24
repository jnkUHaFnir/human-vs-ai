char fileToView[200]; // Changed from char* fileToView[200];
printf("Enter name of desired file: ");
scanf("%s", fileToView); // Removed & from &fileToView

stat(fileToView, buf);
off_t size = buf->st_size;
printf("Size = %lld bytes\n", (long long) size); // Corrected output format specifier for off_t
uid_t owner = buf->st_uid;
printf("Owner UID = %d\n", owner);

