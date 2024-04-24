    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    static pid_t create_process(void)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            fprintf(stderr, "Failed to fork\n");
            exit(1);
        }
        return pid;
    }
    int main(void)
    {
        const char filename[] = "entiers.txt";
        FILE *fichier = fopen(filename, "r");
        int i = 0;
        int n = 0;
        // setbuf(fichier, NULL);
        // setvbuf(fichier, NULL, _IONBF, 0);
        if (fichier == 0)
        {
            fprintf(stderr, "Failed to open file '%s' for reading\n", filename);
            exit(1);
        }
        printf("I am the parent process with the pid %d\n", getpid());
        for (i = 0; i < 10; i++)
        {
            if (fscanf(fichier, "%d\n", &n) != 1)
                break;
            printf("%d\n", n);
        }
        pid_t pid = create_process();
        if (pid == 0)
        {
            printf("I am the child process with the pid %d\n", getpid());
            for (i = 0; i < 10; i++)
            {
                if (fscanf(fichier, "%d\n", &n) != 1)
                    break;
                printf("%d\n", n);
            }
        }
        else
        {
            wait(NULL);
            printf("I am the parent process with the pid %d\n", getpid());
            while (fscanf(fichier, "%d", &n) == 1)
                printf("%d\n", n);
        }
        fclose(fichier);
        return EXIT_SUCCESS;
    }