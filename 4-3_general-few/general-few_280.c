// Allocate memory for the pointers array outside the loop
for (int t = 0; t < T; t++) {
    for (int b = 0; b < B; b++) {
        Matrix[t][b].length = 0;
        Matrix[t][b].size = 60;
        Matrix[t][b].pointers = (Node**)malloc(60 * sizeof(Node*));
    }
}

// Accessing the data structure to add one element
Node* elem = NULL;
Matrix[a][b].pointers[Matrix[a][b].length++] = elem;

// Code to resize the array if needed (using realloc)
if (Matrix[a][b].length >= Matrix[a][b].size) {
    Matrix[a][b].size *= 2;  // Double the size for resizing
    Matrix[a][b].pointers = (Node**)realloc(Matrix[a][b].pointers, Matrix[a][b].size * sizeof(Node*));
}
