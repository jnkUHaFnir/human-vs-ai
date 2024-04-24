typedef struct {
   int *temp;
   int count;
} foo;

int main() {
    foo *fake = (foo*)malloc(1 * sizeof(foo));
    fake->count = 0;

    ++(fake->count);
    fake->temp = (int*)malloc(fake->count * sizeof(int));

    /* I do something */

    /* Now I want to realloc "temp" to increase count */
    ++(fake->count);
    fake->temp = (int*)realloc(fake->temp, fake->count * sizeof(int));

    // Make sure to free the memory when done
    free(fake->temp);
    free(fake);

    return 0;
}
