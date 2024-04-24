Foo **arr = (Foo **)malloc(sizeof(Foo *) * number);
if(array[j]->fieldint < array[j-1]->fieldint) {
    temp = array[j-1]->fieldint;
    array[j-1]->fieldint = array[j]->fieldint;
    array[j]->fieldint = temp;
}
for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > 0; j--) {
        if(array[j]->fieldint < array[j-1]->fieldint) {
            temp = array[j-1]->fieldint;
            array[j-1]->fieldint = array[j]->fieldint;
            array[j]->fieldint = temp;
        }
    }
}
return array;
printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i + 1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
if (array[i]->fieldchar == *X)
