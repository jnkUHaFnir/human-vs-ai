for (ind = count; ind < count + newcount; ind++) {
    ri[ind] = newi[ind - count];
    ci[ind] = newj[ind - count];
}
int *ri = malloc(count * sizeof(int));
int *ci = malloc(count * sizeof(int));

// Check for allocation success
if (ri == NULL || ci == NULL) {
    // Handle allocation failure
    exit(1);
}

// Your code using dynamically allocated arrays

// Don't forget to free the memory when done
free(ri);
free(ci);
