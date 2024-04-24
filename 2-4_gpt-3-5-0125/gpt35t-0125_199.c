#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int opt;
    char cmdline[256] = ""; // Assuming a maximum command line length of 256 characters

    for(int i = 0; i < argc; i++){
        strcat(cmdline, argv[i]); // Concatenate each argument to the cmdline string
        strcat(cmdline, " "); // Add a space between each argument
    }

    printf("Whole command line: %s\n", cmdline);

    while((opt = getopt(argc, argv, "n:i")) != -1) {
        switch (opt){
            case 'n':
                printf("Option 'n' value: %s\n", optarg);
                break;

            case 'i':
                printf("Option 'i' value: %s\n", optarg);
                break;
        }
    }

    return 0;
}
