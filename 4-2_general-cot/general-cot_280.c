#include <stdlib.h>

typedef struct {
    int length;
    int size;
    Node** pointers;
} MatrixElement;

int T = 10; // Assuming T and B are defined somewhere in your code
int B = 10;

MatrixElement Matrix[T][B];

void addElement(int a, int b, Node* elem) {
    Matrix[a][b].length++;
    if (Matrix[a][b].length <= Matrix[a][b].size) {
        Matrix[a][b].pointers[Matrix[a][b].length - 1] = elem;
    }
}

int main() {
    // Memory allocation loop
    for (int t = 0; t < T; t++){
        for (int b = 0; b < B; b++){
            Matrix[t][b].length = 0;
            Matrix[t][b].size = 60;
            Matrix[t][b].pointers = (Node**)malloc(60 * sizeof(Node*));
        }
    }

    // Adding an element
    int a = 0, b = 0;
    Node* elem = NULL;
    addElement(a, b, elem);

    return 0;
}
