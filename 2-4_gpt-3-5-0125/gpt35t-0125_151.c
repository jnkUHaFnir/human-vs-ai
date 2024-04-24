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
    node * head = NULL;
    node * current = NULL;

    ifp = fopen("para.txt","r");

    while(fscanf(ifp,"%s",newword) != EOF){
        node * newNode = (node *)malloc(sizeof(node));
        if(newNode == NULL){
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(newNode->word, newword);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    // Print the linked list
    node * temp = head;
    while(temp != NULL){
        printf("%s\n", temp->word);
        temp = temp->next;
    }

    // Free the memory allocated for nodes
    temp = head;
    while(temp != NULL){
        node * next = temp->next;
        free(temp);
        temp = next;
    }

    // Close file
    fclose(ifp);

    return 0;
}
