char **list_pointers = malloc((argc + 1) * sizeof(char*)); // Allocate memory for array of pointers
int i;

for(i = 0; i < argc; ++i) {
    list_pointers[i] = list[i]; // Assign each pointer from the list to the array of pointers
}

list_pointers[argc] = NULL; // Set the last element of the array to NULL as required by execv

execv(list_pointers[0], list_pointers); // Pass the array of pointers to execv
