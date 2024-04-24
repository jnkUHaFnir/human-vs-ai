int main(void) {
    char name[] = "john doe";
    int name_length = strlen(name) + 1;

    /* Allocate memory for the struct plus the actual name. */
    person *p1 = malloc(sizeof(person) + name_length);

    if (p1 == NULL) {
        /* Handle error here. */
    }

    /* Initialize the fields. */
    p1->age = 30;
    p1->sex = 'm';
    memcpy(p1->name, name, name_length);

    /* Use the struct... */

    /* Free the memory when you're done with it. Don't forget this! */
    free(p1);

    return 0;
}
