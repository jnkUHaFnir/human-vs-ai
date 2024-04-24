char fileToView[200];
printf("Enter name of desired file\n");
scanf("%s", fileToView);

struct stat buf;
stat(fileToView, &buf);
off_t size = buf.st_size;
printf("Size = %ld \n", size);

uid_t owner = buf.st_uid;
printf("owner = %d \n", owner);
