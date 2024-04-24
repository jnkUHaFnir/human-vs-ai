
The `scanf` function returns the number of successfully scanned items, not `EOF`, when it encounters an end-of-file condition. Therefore, you should change the for loop condition to check for the return value of `scanf`:

```csharp
for(int i=0; check != 0; ++i)

With these changes, the modified code would be:

```csharp
int main(void)
{
    setvbuf (stdout, NULL, _IONBF, 0);
    char input[50];
    int check = 1;
    for(int i=0; check != 0; ++i){
        check = scanf("%49s", input);
        printf("%s\n",input);
    }

    fflush(stdout);

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    return 0;
}

char* createList(){
    char* msg = malloc(6*sizeof(char));
    msg[0]='A';
    msg[1]='B';
    msg[2]='C';
    msg[3]='D';
    msg[4]='E';
    msg[5]='\0';
    return msg;
}
