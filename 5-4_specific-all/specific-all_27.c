#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 65536
#define LENGTH 45

typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
} node;

node* global_hash[HASH_SIZE] = {NULL};

int hash_func(const char* hash_val) {
    int h = 0;
    for (int i = 0; i < strlen(hash_val); i++) {
        h = (h << 2) ^ hash_val[i];
    }
    // Ensure h is non-negative
    return (h >= 0) ? h % HASH_SIZE : -h % HASH_SIZE; 
}

bool load(const char *dictionary) {
    char* string = NULL;
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL) {
        fprintf(stdout, "Error: File is NULL.");
        return false;
    }
    while (fscanf(dic, "%ms", &string) != EOF) {
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            return false;
        }
        strcpy(new_node->word, string);
        new_node->next = NULL;
        
        int hash_indx = hash_func(new_node->word);
        node* first = global_hash[hash_indx];
        if (first == NULL) {
            global_hash[hash_indx] = new_node;
        } else {
            new_node->next = global_hash[hash_indx];
            global_hash[hash_indx] = new_node;
        }
        word_size++;
        
        // Free the memory allocated by fscanf
        free(string);
    }
    fclose(dic);
    return true;
}
