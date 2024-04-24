int x = 10; // Replace 10 with the actual number of strings you need
char **array = (char**)malloc(x * sizeof(char*)); // Allocate memory for the array of string pointers

for (int i = 0; i < x; i++) {
    array[i] = (char*)malloc(50 * sizeof(char)); // Allocate memory for each string
}

// Now you can use the array to store your strings
int x = 10; // Replace 10 with the actual number of strings you need
char **array = (char**)calloc(x, sizeof(char*)); // Allocate memory for the array of string pointers

for (int i = 0; i < x; i++) {
    array[i] = (char*)calloc(50, sizeof(char)); // Allocate memory for each string
}

// Now you can use the array to store your strings
