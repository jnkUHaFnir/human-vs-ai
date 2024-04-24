    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main() {
        char *input_str;
        
        /**
         * Dynamic memory allocation.
         * Might crash on windows.
         */
        scanf("%m[^.]", &input_str);
        
        /**
         * Calculate the length of the string.
         */
        size_t len = strlen(input_str);
        
        /**
         * While allocating memory provide
         * two extra cell. One for the character 
         * you want to include.
         * One for the NULL character.
         */
        char *new_str = (char*) calloc (len + 2, sizeof(char));
        
        /**
         * Check for memory allocation.
         */
        if(new_str == NULL) {
            printf("Memory Allocation failed\n");
            exit(1);
        }
        /**
         * Copy the string upto len.
         * Use strncpy instead of 
         * strcpy due to security issues which
         * might not bother you now.
         */
        strncpy(new_str, input_str, len);
        
        /**
         * get your desied terminating character 
         * from buffer
         */
        new_str[len++] = getc(stdin);
        
        /**
         * Append the NULL character
         */
        new_str[len++] = '\0';
        
        /**
         * eat other characters
         * from buffer.
         */
        while(getc(stdin) != '\n');
        
        /**
         * Free the memory used in
         * dynamic memory allocation
         * in scanf. Which is a must
         * according to the scanf man page.
         */
        free(input_str);
    }