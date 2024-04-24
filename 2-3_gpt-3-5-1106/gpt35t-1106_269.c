char **list_pointers = malloc((argc + 1) * sizeof(char*)); // Allocate memory for array of pointers
int i;

for (i = 0; i < argc; i++) {
    list_pointers[i] = list[i]; // Set each pointer in the array to point to the corresponding string in the list
}

list_pointers[argc] = NULL; // Set the last element of the array to NULL

execv(list_pointers[0], list_pointers); // Now you can pass list_pointers to execv
