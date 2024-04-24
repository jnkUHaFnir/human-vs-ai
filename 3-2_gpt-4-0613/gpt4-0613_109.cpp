void print_binary(unsigned char val) {
    for(int i=7; i>=0; i--)
        printf("%c", ((val >> i) & 0x01) ? '1' : '0');
}
char a = 5;
printf("Binary representation of a = ");
print_binary(a);
printf("\n");
