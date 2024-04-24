#include <stdio.h>
#include <string.h>

void convertToDecimal(unsigned char n[], int len, char buffer[]) {
    unsigned long long decimal = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        decimal = decimal * 256 + n[i];
    }
    
    int index = 0;
    while (decimal > 0) {
        buffer[index++] = (decimal % 10) + '0';
        decimal /= 10;
    }
    
    // Reverse the string buffer
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
    
    buffer[index] = '\0';
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    char buffer[100]; // Adjust the size of the buffer as needed
    convertToDecimal(n, 3, buffer);
    
    printf("Decimal representation: %s\n", buffer);
    
    return 0;
}
