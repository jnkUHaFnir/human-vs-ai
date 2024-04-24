    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void) {
    
    char * name[2];
    char * name2[2]={ "emma", "olsson" };
    char inputName[10];
    char names[BUFSIZ];
    int i = 0; 
    
    // case 1
    name[0] = "john";
    name[1] = "doe";
    printf("%s %s\n", name[0],name[1]); //john doe
    
    // case 2
    printf("%s %s\n", name2[0],name2[1]);//emma olsson
    
    // case 3
    for (i = 0; i < 2; i++){
        name[i] = name2[i];
    }
    printf("%s %s\n", name[0],name[1]);//emma olsson
    
    // case 4
    i=0;
    while (fgets(inputName, sizeof(inputName), stdin) != NULL && (i < 2) ){
        strcat(names,inputName);
        i++;
    }
    printf("\n%s\n",names);
    return 0;
    }