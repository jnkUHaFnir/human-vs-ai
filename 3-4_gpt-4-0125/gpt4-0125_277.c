Foo** initialize(int N);
return array;
Foo **arr = initialize(number);
int sort(int N, Foo **array) {
    for (int i=0; i < N-1; i++) {
        for (int j=0; j < N-i-1; j++) {
            if(array[j]->fieldint > array[j+1]->fieldint) {
                Foo *temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return 0;
}
sort(number, arr);
char letter;
fscanf(file, "%d %c", &number, &letter);
printf("Structure %d:\nfield int:%d\nfield char:%c\nfield float:%f\n\n", i+1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
int count(int N, Foo **array, char X);  // Change in function prototype
int result = count(number, arr, letter);
printf("Letter %c appears %d times.\n", letter, result);
if (array[i]->fieldchar == X) {
    counter++;
}
