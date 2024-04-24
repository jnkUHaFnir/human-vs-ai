int any_integer;
char any_string[30];
float any_float;

printf("Please enter an integer, one word string, and a float in one line: ");
scanf("%i %29s %f", &any_integer, any_string, &any_float);
int any_integer;
char any_string[30];
float any_float;
int c;

printf("Please enter an integer, one word string, and a float in one line: ");
scanf("%i %29s %f", &any_integer, any_string, &any_float);

while((c = getchar()) != '\n' && c != EOF);   // to flush newline character if any
for (int i = 0; i < strlen(any_string); ++i) {
    if (!isalpha(any_string[i])) {
        for (int j = i; j < strlen(any_string); ++j) {
            any_string[j] = any_string[j+1];
        }
        i--;    // Decrement i as the characters have shifted position
    }
}
while(1) {   // Infinite loop
    printf("Please enter an integer, one word string, and a float in one line: ");
    scanf("%i %29s %f", &any_integer, any_string, &any_float);
    while((c = getchar()) != '\n' && c != EOF);
    
    if(any_integer == 999) break;  // Terminate the loop with 999
    
    // Add your checking and processing code here
}
