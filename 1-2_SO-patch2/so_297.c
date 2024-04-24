    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, const char * argv[]) {
            int histogram[10000];
            int i;
            while (1) {
                    int *rectPtr = histogram;
                    int size;
                    int retval;
                    printf("Enter the number of elements : ");
                    if ( retval = scanf("%d", &size))       //check here
                    {
                            if (retval == EOF) return 0;        //stop the program
                            if (!size) return 0;
                            printf("Enter %d elements\n", size);
                            for (i = 0; i < size; ++i) {
                                    scanf("%d", rectPtr);
                                    rectPtr++;
                            }
                    }
                    printf("%d\n", 1111111);
                    //    printf("\n");
            }
            return 0;
    }