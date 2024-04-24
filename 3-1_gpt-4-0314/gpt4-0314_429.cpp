#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int processFile(const char *filename, 
                char **ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    if (*ground_truth_filename == NULL)
    {
        *ground_truth_filename = (char *) malloc(strlen(filename) + strlen(".yaml") + 1);
        sprintf(*ground_truth_filename, "%s.yaml", filename);
    }        

    // your other code here
}

int main(int argc, char *argv[])
{
    // ...
    char *ground_truth_filename = NULL;
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
            markupFlag = true;
        }
    }
    
    processFile(filename, &ground_truth_filename);
    // ...
}
free(ground_truth_filename);
