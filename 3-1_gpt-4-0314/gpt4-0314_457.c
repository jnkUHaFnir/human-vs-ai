ri[ind]=newi[ind-count+newcount];
if (ind-count+newcount >= 0 && ind-count+newcount < 4) {
    ri[ind]=newi[ind-count+newcount];
    ci[ind]=newj[ind-count+newcount];
}
int *ri = (int *)malloc(count * sizeof(int));
int *ci = (int *)malloc(count * sizeof(int));
ri = (int *)realloc(ri, (count + newcount) * sizeof(int));
ci = (int *)realloc(ci, (count + newcount) * sizeof(int));
free(ri);
free(ci);
