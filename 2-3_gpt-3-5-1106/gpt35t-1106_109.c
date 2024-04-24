void printBinary(int num) {
    if (num > 1) {
        printBinary(num/2);
    }
    printf("%d", num % 2);
}

int main() {
    int a = 5;
    printf("binary representation of a = ");
    printBinary(a);
    return 0;
}
