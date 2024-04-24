int *array = NULL;
int count = 0;
int new_element = some_value; // Replace this with the actual value you want to add
int *temp = realloc(array, (count + 1) * sizeof(int));
if (temp == NULL) {
    // Handle memory allocation error here
} else {
    array = temp;
    array[count] = new_element;
    count++;
}
free(array);
