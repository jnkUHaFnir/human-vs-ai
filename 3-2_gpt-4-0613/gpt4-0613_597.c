char fileToView[200];
printf("Enter name of desired file\n");
scanf("%s", fileToView);

if(stat(fileToView, buf) == -1){
	perror("stat");
	return(EXIT_FAILURE);
}
off_t size = buf -> st_size;
printf("Size = %ld \n", size);

uid_t owner = buf ->st_uid;
printf("owner = %u \n", owner);
