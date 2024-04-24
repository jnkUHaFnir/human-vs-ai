    #include <stdio.h>
    #include <stdlib.h>
    int main(void) {
        char address[1000] ;
        printf("Enter you address : ") ;
        if ( fgets( address, 1000, stdin) == NULL )
        {
            printf("Deal whith the Error\n");
            exit( EXIT_FAILURE );
        }
        printf("Your address is : %s\n", address);
    }