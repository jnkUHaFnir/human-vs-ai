#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct product {
    char *title;
    char code[8];
    int stock;
    double price;
    struct product *next;
};

struct product_list {
    struct product *head;
};

void init_list(struct product_list *list) {
    list->head = NULL; // Initialize head to NULL as the list is empty
}

struct product *add_product(struct product_list *list, const char *title, const char *code, int stock, double price) {
    struct product *new_product = malloc(sizeof(struct product));
    new_product->title = malloc(strlen(title) + 1);
    strcpy(new_product->title, title);
    strncpy(new_product->code, code, 7);
    new_product->code[7] = '\0';
    new_product->stock = stock;
    new_product->price = price;
    new_product->next = NULL;

    // If the list is empty, update the head
    if (list->head == NULL) {
        list->head = new_product;
    } else {
        struct product *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_product;
    }

    return new_product;
}

struct product *find_product(struct product_list *list, const char *code) {
    struct product *current = list->head;
    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int remove_product(struct product_list *list, const char *code) {
    struct product *current = list->head;
    struct product *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            if (prev == NULL) { // Removing the head
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->title);
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

void delete_list(struct product_list *list) {
    struct product *current = list->head;
    struct product *next;

    while (current != NULL) {
        next = current->next;
        free(current->title);
        free(current);
        current = next;
    }

    list->head = NULL;
}

void print_product(struct product *p) {
    printf("%s (%s) -- stock: %d, price: %lf\n", p->title, p->code, p->stock, p->price);
}

int main() {
    struct product_list list;
    struct product *p;

    init_list(&list);
    add_product(&list, "test", "1234", 1, 0.50);
    add_product(&list, "Product 1", "0000", 0, 10);
    add_product(&list, "Long name, isn't it", "1234567890", 10, 100);
    add_product(&list, "Product 3", "9999999", 0, 20);

    p = find_product(&list, "0000");
    if (p) {
        print_product(p);
    } else {
        printf("Not found\n");
    }

    int i = remove_product(&list, "0000");
    printf("Removed %d items\n", i);

    delete_list(&list);

    return 0;
}
