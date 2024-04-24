#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int opt;
    char commandLine[1024] = ""; // Assuming a maximum length for the command line

    for(int i = 0; i < argc; i++){
        strcat(commandLine, argv[i]);
        strcat(commandLine, " ");
    }

    printf("Whole command line: %s\n", commandLine);

    while((opt = getopt(argc, argv, "n:i:")) != -1) {
        switch (opt) {
            case 'n':
                printf("n was %s\n", optarg);
                break;

            case 'i':
                printf("i was %s\n", optarg);
                break;

            default:
                break;
        }
    }

    return 0;
}
