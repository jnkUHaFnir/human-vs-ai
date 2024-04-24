#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct product {
    char *title;  // Name of the product
    char code[8]; // Max. 7 characters of product ID
    int stock;  // Current stock (number of units)
    double price;  // Price of a single unit
    struct product *next; // pointer to next item in linked list
};

struct product_list {
    struct product *head;
};

void init_list(struct product_list *list) {
    list->head = NULL; // Initialize the head node to NULL
}

struct product *add_product(struct product_list *list, const char *title, const char *code, int stock, double price) {
    struct product *newProduct = malloc(sizeof(struct product));
    newProduct->title = malloc(strlen(title) + 1);
    strcpy(newProduct->title, title);
    strncpy(newProduct->code, code, 7);
    newProduct->code[7] = '\0';
    newProduct->stock = stock;
    newProduct->price = price;
    newProduct->next = NULL;

    if (list->head == NULL) {
        list->head = newProduct;
    } else {
        struct product *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }

    return newProduct;
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
    
    if (current != NULL && strcmp(current->code, code) == 0) {
        list->head = current->next;
        free(current->title);
        free(current);
        return 1;
    }

    while (current != NULL && strcmp(current->code, code) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0; // Product not found
    }

    prev->next = current->next;
    free(current->title);
    free(current);
    return 1;
}

int delete_list(struct product_list *list) {
    struct product *current = list->head;
    while (current != NULL) {
        struct product *temp = current;
        current = current->next;
        free(temp->title);
        free(temp);
    }
    list->head = NULL; // Reset head to NULL after deleting all nodes
    return 1;
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
    if (p != NULL) {
        print_product(p);
    } else {
        printf("Not found\n");
    }

    int items_removed = remove_product(&list, "0000");
    printf("Removed %d items\n", items_removed);

    delete_list(&list);

    return 0;
}
