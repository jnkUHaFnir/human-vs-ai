#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[20];
    struct node * next;
}node;

void insert(node ** head, char newword[20])
{
    node * new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->word, newword);
    new_node->next = *head;
    *head = new_node;
}

int main(){
    FILE *ifp;
    char newword[20];
    node * head = NULL;

    if ((ifp = fopen("para.txt","r")) == NULL){
        printf("Error opening file");
        return 1;  // return with error code
    }
  
    while(fscanf(ifp,"%s",newword) != EOF){
        insert(&head, newword);
    }
  
    fclose(ifp);

    //print linked list
    while(head){
        printf("%s\n", head->word);
        head=head->next;
    }

    return 0;
}
node *current = head;
while(current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
}
