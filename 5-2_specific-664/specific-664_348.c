int add_even(int num) {
    static int sum = 0;

    if (num % 2 != 0) {
        return 0;
    }

    sum += num;
    return sum;
}

int add_odd(int num) {
    static int sum = 0;

    if (num % 2 == 0) {
        return 0;
    }
    sum += num;
    return sum;
}
if (num % 2 == 0) { // checking for even number
    printf("even\n");
    even_count++;
} else if(num != 0) { // checking for odd number
    printf ("odd\n");
    odd_count++;
}
