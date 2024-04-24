for(ind=count-newcount;ind<count;ind++)/////
{
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
count=count+newcount;
int ri[(n-2)*(n-2)];
int ci[(n-2)*(n-2)];
int *ri = malloc(sizeof(int) * (n-2)*(n-2));
int *ci = malloc(sizeof(int) * (n-2)*(n-2));
int allocated_size = (n-2)*(n-2); // remember how many elements you've allocated
// do processing
// Remember to check if count exceeds allocated_size, and if so, use realloc to increase the size
// Free memory when done
free(ri);
free(ci);
