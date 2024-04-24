#include <stdio.h>

// Your target function
void my_function() {
    printf("Called my_function\n");
}

// Generated code with the desired number of iterations
void call_my_function_x_times() {
    my_function();
    my_function();
    my_function();
    // Continue adding my_function() calls for your desired number of times
}

int main() {
    call_my_function_x_times();
    return 0;
}
