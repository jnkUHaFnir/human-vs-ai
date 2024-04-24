Foo **array;
array = (Foo **)malloc(sizeof(Foo*) * N);
return array;
for (int j=N-1;j>=i;j--) {
int temp;
temp = array[j-1].fieldint;
array[j-1].fieldint = array[j].fieldint;
array[j].fieldint = temp;
