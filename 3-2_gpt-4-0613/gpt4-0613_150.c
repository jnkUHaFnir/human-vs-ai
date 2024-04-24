/* dynamically allocate memory for foo */
foo = (float *)malloc(a * 2 * sizeof(float));

/* some code... */

/* re-allocate memory */
float* new_mem = (float *)realloc(foo, a * 2 * sizeof(float));
if (new_mem == NULL) {
    /* handle realloc fail, e.g., free original foo and exit */
    free(foo);
    return;
} else {
    foo = new_mem;
    bar = foo;
}

/* or you can directly re-assign it to bar */
/* bar = (float *)realloc(foo, a * 2 * sizeof(float)); */
  
/* some code... */

/* don't free foo, cause it is now bar, and freeing it would make bar an illegal pointer */
/* free(foo); */

/* Now you can freely use bar and remember to free it */
if(bar != NULL)
{
    free(bar); /* <-- no error at executing anymore */
}
