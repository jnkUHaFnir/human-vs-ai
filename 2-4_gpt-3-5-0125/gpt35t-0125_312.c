#include <stdio.h>

struct book { 
    char name[20];
};

int main(){
    struct book buk[10];
    int i;
    char c;

    for(i=0; i<3; i++){
        printf("Enter name of book %d: ", i+1);
        scanf("%[^\n]s", buk[i].name);
        while((c = getchar()) != '\n' && c != EOF); // consume the newline character
    }

    for(i=0; i<3; i++){
        printf("Name of book %d: %s\n", i+1, buk[i].name);
    }

    return 0;
}
