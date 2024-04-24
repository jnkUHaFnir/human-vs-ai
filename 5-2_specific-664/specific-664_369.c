Foo *arr[number]; 
*arr = initialize(number);
Foo **arr = initialize(number);
Foo *initialize(int N) { 
    Foo **array;
    array = (Foo **)malloc(sizeof(Foo) * N);
    ...
    return *array; 
}
Foo **initialize(int N) { 
    Foo **array = (Foo **)malloc(sizeof(Foo*) * N);
    ...
    return array; 
}
if(array[j].fieldint < array[j-1].fieldint) {
    temp = array[j-1].fieldint;
    array[j-1].fieldint = array[j].fieldint;
    array[j].fieldint = temp;
}
if(array[j]->fieldint < array[j-1]->fieldint) {
    temp = array[j-1]->fieldint;
    array[j-1]->fieldint = array[j]->fieldint;
    array[j]->fieldint = temp;
}
if (array[i].fieldchar == 'X') {
if (array[i]->fieldchar == *X) {
