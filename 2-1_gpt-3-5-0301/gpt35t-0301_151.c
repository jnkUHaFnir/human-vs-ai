#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[20];
    struct node * next;
}node;

int main(){
    FILE *ifp;
    char newword[20];
    node * head, * current;

    ifp = fopen("para.txt","r");
    head = NULL;

    while(fscanf(ifp,"%s",newword) != EOF){
        node * newnode = (node *) malloc(sizeof(node));
        if (newnode == NULL){
            printf("Memory allocation error\n");
            return 1;
        }
        strcpy(newnode->word, newword);
        newnode->next = NULL;

        if (head == NULL){
            head = newnode;
            current = newnode;
        }
        else{
            current->next = newnode;
            current = newnode;
        }
    }

    fclose(ifp);

    // Print the linked list
    current = head;
    while(current != NULL){
        printf("%s\n", current->word);
        current = current->next;
    }

    // Free memory
    current = head;
    while(current != NULL){
        node * temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
