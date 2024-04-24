pid_t pid;
int status;
FILE* fichier;
int n = 0;

pid = fork();

if(pid == 0) {  // Child process
    fichier = fopen("entiers.txt", "r");
    fseek(fichier, 30, SEEK_SET); // Adjust this value, it would also depend on how your prime numbers are formatted in your file.
    for(int i=0; i<10; i++) {
        fscanf(fichier, "%d\n", &n);
        printf("Child: %d\n", n);
    }
    fclose(fichier);
    exit(0);
}
else if(pid > 0) {  // Parent process
    fichier = fopen("entiers.txt", "r");
    for(int i=0; i<10; i++) {
        fscanf(fichier, "%d\n", &n);
        printf("Parent: %d\n", n);
    }
    fclose(fichier);
    wait(&status);  // Wait for the child process to finish
}

return 0;
