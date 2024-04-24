Foo **initialize(int N) { // Returning an array of pointers
     Foo **array = (Foo **)malloc(sizeof(Foo*) * N); // Allocate an array of pointers
     srand(time(NULL));

     for(int i = 0; i < N; i++) {
          array[i] = (Foo*)malloc(sizeof(Foo)); // Allocate each structure individually         
          array[i]->fieldint = rand(); // random number
          array[i]->fieldchar = (char)(rand() % 26) + 65; // random letter A to Z
          array[i]->fieldfloat = i;
     }

     return array; // Return a pointer to the array of pointers
}
Foo **arr = initialize(number); // arr is now an array of pointers
int sort(int N, Foo **array) { // Accept Foo** rather than Foo*
     Foo *temp; // Change temp to be a pointer to Foo
     for(int i = 0; i < N-1; i++) { // Outer loop goes to N-1
         for(int j = 0; j < N-i-1; j++) { // Changed logic to bubble sort correctly
             if(array[j]->fieldint > array[j+1]->fieldint) {
                // Swap pointers instead of int values
                 temp = array[j];
                 array[j] = array[j+1];
                 array[j+1] = temp;
             }
         }
     }
     return 0;
}
sort(number, arr);
int count(int N, Foo **array, char X){ // Change X to char instead of char*
     int counter = 0;
     for(int i=0; i < N; i++) {
         if (array[i]->fieldchar == X) { // Direct comparison
             counter++;
         }
     }
     return counter;
}
int totalCount = count(number, arr, letter[0]);
printf("%d occurrences of %c\n", totalCount, letter[0]);
