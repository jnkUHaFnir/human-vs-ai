Query* new_query = malloc(sizeof(Query));
int size = 4; // size calculated based on your calculations
new_query->pages = malloc(size * sizeof(int));

if (new_query->pages == NULL) {
    // handle error, memory allocation failed
}

// Now you can access and use the pages array as needed
new_query->currentpage = 0;
free(new_query->pages);
free(new_query);
