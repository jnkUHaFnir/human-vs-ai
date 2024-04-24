#include <stdio.h>
#include <stdlib.h>

struct Query {
    int currentpage;
    int pages[]; // Flexible Array Member
};

int main() {
    int arraySize = 4;
    
    // Dynamically allocate memory for the structure along with space for 'arraySize' elements
    struct Query* new = malloc(sizeof(struct Query) + arraySize * sizeof(int));
    
    if (new != NULL) {
        new->currentpage = 0; // Set the initial value for currentpage
        
        // Now 'pages[]' can be accessed like a regular array
        for (int i = 0; i < arraySize; i++) {
            new->pages[i] = i; // Set some example values
        }
        
        // Use 'new' as needed
        
        // Don't forget to free the allocated memory when done
        free(new);
    } else {
        // Handle allocation failure
        perror("malloc failed");
    }
    
    return 0;
}
