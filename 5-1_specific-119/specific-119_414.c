#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct  Person {
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;
 
char * getString(void);

int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,j;
    char c;
    char *tmp = NULL;
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        getchar();
        switch(c){
            case 'i':
                ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
                if(ttmp == NULL){
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                else
                    rub = ttmp;
                printf("Nome: ");
                tmp = getString();
                rub[idx].name = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].name, tmp);
                printf("Surname: ");
                tmp = getString();
                rub[idx].surname = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].surname, tmp);
                printf("Address: ");
                tmp = getString();
                rub[idx].address = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].address, tmp);
                printf("Number: ");
                tmp = getString();
                rub[idx].number = (char *) malloc(strlen(tmp) + 1);
                strcpy(rub[idx].number, tmp);
                idx++;
                for(j=0;j<idx;j++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", j+1, rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                }
                break;
            case 'n':
                printf("What name are you looking for? ");
                tmp = getString();
                for(j=0;j<idx;j++){
                    if(strcmp(rub[j].name,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                    }
                }
                break;
            case 'c':
                printf("What surname are you looking for? ");
                tmp = getString();
                for(j=0;j<idx;j++){
                    if(strcmp(rub[j].surname,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                    }
                }
                break;
            case 'e':
                printf("Select number to delete record:\n ");
                for(j=0;j<idx;j++){
                    printf("%d) %s %s\n", j+1, rub[j].name,rub[j].surname);
                }
                scanf("%d",&i);
                ttmp = (struct Person *) malloc((idx-1)*sizeof(Person));
                for(j=0,i=0;j<idx;j++){
                    if(j+1 != i){
                        ttmp[i].name = (char *) malloc(strlen(rub[j].name) + 1);
                        strcpy(ttmp[i].name, rub[j].name);
                        ttmp[i].surname = (char *) malloc(strlen(rub[j].surname) + 1);
                        strcpy(ttmp[i].surname, rub[j].surname);
                        ttmp[i].address = (char *) malloc(strlen(rub[j].address) + 1);
                        strcpy(ttmp[i].address, rub[j].address);
                        ttmp[i].number = (char *) malloc(strlen(rub[j].number) + 1);
                        strcpy(ttmp[i].number, rub[j].number);
                        i++;
                    }
                }
                idx--;
                free(rub);
                rub = ttmp;
                for(j=0;j<idx;j++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", j+1, rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                }
                break;
            case 'p':
                for(j=0;j<idx;j++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", j+1, rub[j].name,rub[j].surname,rub[j].address,rub[j].number);
                }
                break;
            case '0':
                free(rub);
                return 0;
            default:
                break;
        }
        fseek(stdin,0,SEEK_END);
    } while(c != '0');
    return 0;
}
 
char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+1)*sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
}
