char dirToView[200];
char fileToView[200];
scanf("%s", dirToView);
char dirToView[200];
printf("Enter path of desired directory\n");
scanf("%s", dirToView);

current_directory_ptr = opendir(dirToView);

// ... (rest of your code)

char fileToView[200];
printf("Enter name of desired file\n");
scanf("%s", fileToView);

stat(fileToView, buf);
off_t size = buf -> st_size;
printf("Size = %ld \n", size);

uid_t owner = buf -> st_uid;
printf("owner = %d \n", owner);
