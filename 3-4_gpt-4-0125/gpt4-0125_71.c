#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *var = "variable content";
    char *foo = "foo content";
    char *bar = "bar content";

    // The size should be calculated based on the content you're adding.
    // Here, we are making a buffer large enough to hold everything.
    // 5 for "TEXT ", the length of var, and 1 for the null terminator.
    size_t message_size = 5 + strlen(var) + 1;
    char *message = malloc(message_size);

    // Always check if malloc was successful
    if (message != NULL) {
        strcpy(message, "TEXT ");
        strcat(message, var);

        printf("%s\n", message);
      
        // Now, for the more complex concatenation, calculate the size first.
        size_t message2_size = 5 + strlen(foo) + 6 + strlen(bar) + 1;
        char *message2 = malloc(message2_size);
      
        if (message2 != NULL) {
            strcpy(message2, "TEXT ");
            strcat(message2, foo);
            strcat(message2, " TEXT ");
            strcat(message2, bar);

            printf("%s\n", message2);

            // Remember to free your allocated memory
            free(message2);
        } else {
            printf("Allocation for message2 failed\n");
        }
      
        free(message);
    } else {
        printf("Allocation for message1 failed\n");
    }
  
    return 0;
}
