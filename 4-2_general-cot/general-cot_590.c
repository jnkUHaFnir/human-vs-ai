#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Car {
    char plate[MAX_LEN];
    int mileage;
    // Add other fields here
} Car;

typedef struct Node {
    Car data;
    struct Node* next;
} Node;

Node* initializeCar(int mileage, char* plate) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data.mileage = mileage;
    strncpy(newNode->data.plate, plate, MAX_LEN - 1);
    newNode->data.plate[MAX_LEN - 1] = '\0'; // Ensure null-terminated

    newNode->next = NULL;

    return newNode;
}

Node* addList(Node* head, Car data) {
    Node* newNode = initializeCar(data.mileage, data.plate);
    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

int main() {
    FILE *filePointer = fopen("filename.txt", "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }

    char fileOutput[MAX_LEN];
    char *inputPlate;
    char *string;
    int mileage;
    
    Node* avail = NULL;

    while (fgets(fileOutput, MAX_LEN, filePointer) != NULL) {
        inputPlate = strtok(fileOutput, " ");
        if (inputPlate == NULL) {
            continue; // Skip empty lines
        }

        string = strtok(NULL, " ");
        if (string == NULL) {
            continue; // Skip lines with no mileage
        }

        mileage = atoi(string);

        Node* car = initializeCar(mileage, inputPlate);
        avail = addList(avail, car);

        // Print the added car for debugging
        printf("Added Car: Plate: %s, Mileage: %d\n", car->data.plate, car->data.mileage);
    }

    // Cleanup - Free allocated memory for the linked list
    Node* current = avail;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    fclose(filePointer);
    
    return 0;
}
