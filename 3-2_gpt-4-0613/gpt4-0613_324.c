// Let's suppose x has some positive integer value
int x; 

// Dynamically allocate memory using malloc()
char** array = (char**)malloc(x * sizeof(char*));

for(int i = 0; i < x; i++) {
    array[i] = (char*)malloc(50 * sizeof(char));  
}
// Your code here, using array...

// Don't forget to free memory
for(int i = 0; i < x; i++) {
    free(array[i]);
}
free(array);
