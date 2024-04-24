#include <stdio.h>

int main() {
    FILE* file;
    char filename[] = "/home/your_username/downloads/grades.txt";
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // File is open, you can read the contents here
    
    fclose(file);
    
    return 0;
}
