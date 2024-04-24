// Parent process
for (i = 0; i < 10; i++)
{
    fscanf(fichier, "%d\n", &n);
    printf("%d\n", n);
}

pid_t pid = create_process();

if (pid > 0) // Parent Process
{
    wait(NULL); // Wait for child to finish

    // After the child, read the next ten numbers from the file
    printf("I am the father process of the pid %d\n", getpid());
    for (int j = 0; j < 10; j++)
    {
        if (fscanf(fichier, "%d\n", &n) == 1)
            printf("%d\n", n);
        else
            break; // If reading fails, break out of the loop
    }

    fclose(fichier); // Close the file as it's no longer needed
}

if (pid == 0) // Child Process
{
    printf("I am the child process of the pid %d\n", getpid());

    for (i = 0; i < 10; i++)
    {
        fscanf(fichier, "%d\n", &n);
        printf("%d\n", n);
    }

    fclose(fichier); // Close the file in the child process
    exit(0); // Ensure child process exits after doing its work
}
