if (pid)
{
    wait(NULL);  // Wait for the child to finish its activity

    printf("I am the father process of the pid %d\n", getpid());
    while (fscanf(fichier, "%d\n", &n) != EOF)  // Use fscanf to continue reading integers
    {   
        printf("%d\n", n);               
    }

    fclose(fichier);  // Close file when done
    // No need to kill the child as it has already terminated
}
