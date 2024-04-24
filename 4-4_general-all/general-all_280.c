// Allocate memory for all elements at once
for(int t = 0; t < T; t++){
    for(int b = 0; b < B; b++){
        Matrix[t][b].length = 0;
        Matrix[t][b].size = 60;
    }
}

// Allocate memory for all pointers in a single block
for(int t = 0; t < T; t++){
    for(int b = 0; b < B; b++){
        Matrix[t][b].pointers = (Node**)malloc(60*sizeof(Node*));
    }
}

// Accessing the data structure to add one element
Node* elem = NULL;
Matrix[a][b].length++;
if(Matrix[a][b].length < Matrix[a][b].size) {
    Matrix[a][b].pointers[Matrix[a][b].length] = elem;
}
``` 

In this code snippet, the memory for `Matrix[t][b].pointers` is allocated only once in a single block, which can improve memory management and reduce overhead compared to allocating memory for each element individually. Make sure to free this memory appropriately when it is no longer needed.
