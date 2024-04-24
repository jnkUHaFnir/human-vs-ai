// Save the original count before modification
int origCount = count;

for(ind = 0; ind < newcount; ind++) {
    ri[count+ind] = newi[ind];
    ci[count+ind] = newj[ind];
}

// Update the count after all new elements have been added
count = count + newcount;
int* ri = (int*)malloc(count * sizeof(int));
int* ci = (int*)malloc(count * sizeof(int));

// Your code here

free(ri);
free(ci);
