    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void) {
    
    // case 1
    
    char* name[2];
    //name[0] = (char*)malloc(sizeof(char*) * 10); 
    //name[1] = (char*)malloc(sizeof(char*) * 10);
    name[0] = "john";
    name[1] = "doe";
    printf("%s\n", name[0]); // prints john
    printf("%s\n", name[1]); 
    
    // case 2
    
    char* name2[2] = { "emma", "olsson" };
    printf("%s\n", name2[0]); // prints emma
    printf("%s\n", name2[1]); // prints olsson
    
    // case 3
    
    for (int i = 0; i < 2; i++)
    {
        name[i] = name2[i];
    }
    printf("%s\n", name[0]); // prints emma
    printf("%s\n", name[1]); // prints olsson
    
    // case 4
    
    char inputName[10];
    
    int i = 0; 
    while (i < 2  )
    {
    fgets(inputName, sizeof(inputName), stdin); // first input: Max   second input: Payne
    char* pos = strchr(inputName, '\n');
    if (pos != NULL)
        *pos = '\0';
    name[i] = inputName;
    printf("%s\n",name[i++]);
    }
    }