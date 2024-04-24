void swap(struct student *pointer) {
    if (pointer == NULL || pointer->next == NULL) {
        return; // Cannot swap if pointer or pointer->next is NULL
    }

    struct student *previousNode = pointer->previous;
    struct student *currentNode = pointer;
    struct student *nextNode = pointer->next;
    struct student *afterNextNode = nextNode->next;

    if (previousNode != NULL) {
        previousNode->next = nextNode;
    }

    nextNode->previous = previousNode;
    nextNode->next = currentNode;
    currentNode->previous = nextNode;
    currentNode->next = afterNextNode;

    if (afterNextNode != NULL) {
        afterNextNode->previous = currentNode;
    }

    if (currentNode == first) {
        first = nextNode;
    }

    if (nextNode == last) {
        last = currentNode;
    }
}
void sort(void) {
    int swapped;
    struct student *pointer;
    struct student *temp = NULL;

    if (first == NULL) {
        return; // Empty list
    }

    do {
        swapped = 0;
        pointer = first;

        while (pointer->next != temp) {
            if (strcmp(pointer->Nachname, pointer->next->Nachname) > 0) {
                swap(pointer);
                swapped = 1;
            }
            pointer = pointer->next;
        }
        temp = pointer;
    } while (swapped);
}
