typedef struct {
    char *string;
} record;

record records[18446744073709551616];

void set(unsigned long long A, char *B) {
    records[A].string = B;
}

char* get(unsigned long long A) {
    return records[A].string;
}

This implementation will use less memory than the first approach because of the dynamic memory allocation, and it should fulfill the requirement that both set and get operations should be O(1). 
However, it should be noted that on rare occasions, due to hash collisions, accessing the hash map could degenerate to an O(n) operation.
