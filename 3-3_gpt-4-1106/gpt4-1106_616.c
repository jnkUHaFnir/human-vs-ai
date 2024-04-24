double removeLowestValue() {
    struct node *temp;
    struct node *ptr = head;
    double val = ptr->value;

    if (head == NULL) {
        // If the list is empty
        return -1; // Consider returning a sentinel value or an error code.
    } else if (head == tail) {
        // If there's only one element in the list
        free(head);
        head = NULL;
        tail = NULL;
        return val;
    } else {
        temp = NULL;
        while (ptr->next != NULL && ptr->next->value == val) {
            temp = ptr;
            ptr = ptr->next;
        }
        if (temp == NULL) {
            // No duplication of the head's value, remove the head itself
            head = ptr->next;
        } else {
            // Duplication found, remove the last duplicate
            temp->next = ptr->next;
            if (ptr == tail) {
                // Ensure tail still points to the last node
                tail = temp;
            }
        }
        free(ptr);
        return val;
    }
}
int main() {
    // Assuming insertNode function is correctly implemented
    insertNode(18.0);
    insertNode(13.0);
    insertNode(11.0);
    insertNode(11.0);
    insertNode(22.0);

    printf("%lf\n", removeLowestValue());

    // Additional code to print the list or clean up resources...

    return 0;
}
