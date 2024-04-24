#include <stdio.h>
#include <getopt.h>
#include <string.h>


int main(int argc, char* argv[]) {
    int opt;
    char str[1024] = ""; // Allocate sufficient memory for the string
    int i;

    // Concatenate all command line arguments into a single string
    for(i = 1; i < argc; i++){
        strcat(str, argv[i]);
        strcat(str, " "); // Add a space between arguments
    }

    printf("The whole command line is: %s\n", str);

    while((opt = getopt(argc, argv, "n:i")) != -1) {
        switch (opt){
            case 'n':
                     printf("n was %s\n", optarg);
                     break;

            case 'i':
                     printf("i was %s\n", optarg);
                     break;
        }
    }
    return 0;
}
