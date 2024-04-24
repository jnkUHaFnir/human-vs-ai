FILE *file = fopen("input.txt", "r");
if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
}

char sign;
int number_before_dot;
int number_after_dot;
int exponent;
int items_read;

while(!feof(file)) {
    items_read = fscanf(file, "%c%d.%dE%d;", &sign, &number_before_dot, &number_after_dot, &exponent);

    if (items_read == 4) {
        printf("Sign: %c, Before dot: %d, After dot: %d, Exponent: %d\n", sign, number_before_dot, number_after_dot, exponent);
    } else {
        printf("Failed to parse a value, only %d items read\n", items_read);
    }
}

fclose(file);
