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

    ifp = fopen("para.txt", "r");
    if (ifp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    while(fscanf(ifp, "%19s", newword) != EOF){
         node * new_node = (node *)malloc(sizeof(node));
         if (new_node == NULL){
             printf("Memory allocation failed.\n");
             return 1;
         }

         strcpy(new_node->word, newword);
         new_node->next = NULL;

         if (head == NULL){
             head = new_node;
             current = new_node;
         } else {
             current->next = new_node;
             current = new_node;
         }
     }

    // Print the linked list
    current = head;
    while (current != NULL){
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");

    // Free the memory
    current = head;
    while (current != NULL){
        node * temp = current;
        current = current->next;
        free(temp);
    }

    fclose(ifp);
    return 0;
}
