for(ind=count-newcount;ind<count;ind++)/////
{
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
int *ri = malloc(initial_count * sizeof(int));
if (ri == NULL) {
    // Handle memory allocation failure
}

int *ci = malloc(initial_count * sizeof(int));
if (ci == NULL) {
    free(ri); // Free the previously allocated memory
    // Handle memory allocation failure
}

// ... use ri and ci ...

// Before adding more elements, resize the arrays
int new_size = ...; // calculate the new size
ri = realloc(ri, new_size * sizeof(int));
ci = realloc(ci, new_size * sizeof(int));

// ... use the resized ri and ci ...

// Don't forget to free the memory when done
free(ri);
free(ci);
