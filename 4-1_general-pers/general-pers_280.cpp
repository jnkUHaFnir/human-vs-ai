// Allocate memory outside the nested loops
Node*** Matrix = (Node***)malloc(T * sizeof(Node**));
for(int t = 0; t < T; t++){
    Matrix[t] = (Node**)malloc(B * sizeof(Node*));
    for(int b = 0; b < B; b++){
        Matrix[t][b] = (Node*)malloc(60 * sizeof(Node));
        Matrix[t][b].length = 0;
        Matrix[t][b].size = 60;
    }
}

// Access element after increasing the length
Node* elem = NULL;
Matrix[a][b].pointers[Matrix[a][b].length] = elem;
Matrix[a][b].length++;

// Free the allocated memory when it is no longer needed
for(int t = 0; t < T; t++){
    for(int b = 0; b < B; b++){
        free(Matrix[t][b]);
    }
    free(Matrix[t]);
}
free(Matrix);
