typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
    struct Data *prev;
} Data;
#define HASH_SIZE 1000000
Data *hashTable[HASH_SIZE];
void set(unsigned long long A, char *B) {
    int index = A % HASH_SIZE;
    Data *newData = (Data*)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B);
    
    if(hashTable[index] != NULL) {
        newData->next = hashTable[index];
        hashTable[index]->prev = newData;
    }
    
    hashTable[index] = newData;
}
char* get(unsigned long long A) {
    int index = A % HASH_SIZE;
    Data *curr = hashTable[index];
    
    while(curr != NULL) {
        if(curr->A == A) {
            return curr->B;
        }
        curr = curr->next;
    }
    
    return NULL;
}
