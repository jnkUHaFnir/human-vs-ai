#include "products.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(struct product_list *list) {
    list->head = NULL;  // Initialize the head of the list to NULL
}

struct product *add_product(struct product_list *start, const char *title, const char *code, int stock, double price) {
    struct product *new_product = malloc(sizeof(struct product));
    new_product->title = strdup(title);
    strncpy(new_product->code, code, 7);
    new_product->code[7] = '\0';
    new_product->stock = stock;
    new_product->price = price;
    new_product->next = NULL;

    if (start->head == NULL) {
        start->head = new_product;
    } else {
        struct product *current = start->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_product;
    }

    return new_product;
}

struct product *find_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    struct product *prev = NULL;
    int removed = 0;

    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            if (prev == NULL) {
                start->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->title);
            free(current);
            removed = 1;
            break;
        }
        prev = current;
        current = current->next;
    }

    return removed;
}

int delete_list(struct product_list *start) {
    struct product *current = start->head;
    while (current != NULL) {
        struct product *next = current->next;
        free(current->title);
        free(current);
        current = next;
    }
    start->head = NULL;
    return 1;
}
