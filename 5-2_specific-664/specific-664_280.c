Node* elem = NULL;
// Check if the length is within bounds before adding an element
if(Matrix[a][b].length < Matrix[a][b].size) {
    // Increment the length after accessing the correct index
    Matrix[a][b]->pointers[Matrix[a][b].length] = elem;
    Matrix[a][b].length++;
} else {
    // Handle error: Matrix[a][b] is full
}
