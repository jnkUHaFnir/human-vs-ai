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
    list->head = NULL;
}

struct product *add_product(struct product_list *start, const char *title, const char *code, 
                            int stock, double price) {
    struct product *newProduct = malloc(sizeof(struct product));
    newProduct->title = malloc(strlen(title) + 1);
    strcpy(newProduct->title, title);
    strncpy(newProduct->code, code, 7);
    newProduct->code[7] = '\0';
    newProduct->stock = stock;
    newProduct->price = price;
    newProduct->next = NULL;

    if (start->head == NULL) {
        start->head = newProduct;
    } else {
        struct product *current = start->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }
    
    return newProduct;
}

struct product *find_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int remove_product(struct product_list *start, const char *code) {
    struct product dummy = {.next = start->head}; // Adding a dummy node for easier removal
    struct product *prev = &dummy;
    struct product *current = start->head;
    int removed = 0;

    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            prev->next = current->next;
            free(current->title);
            free(current);
            start->head = dummy.next; // Reset the list head if the first element is removed
            removed = 1;
            break;
        }
        prev = current;
        current = current->next;
    }

    return removed;
}

int delete_list(struct product_list *listhead) {
    struct product *current = listhead->head;
    while (current != NULL) {
        struct product *temp = current;
        current = current->next;
        free(temp->title);
        free(temp);
    }
    listhead->head = NULL;
    
    return 1;
}

void print_product(struct product *p) {
    printf("%s (%s) -- stock: %d, price: %lf\n",
           p->title, p->code, p->stock, p->price);
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

    int removed = remove_product(&list, "0000");
    printf("Removed %d items\n", removed);

    delete_list(&list);

    return 0;
}
