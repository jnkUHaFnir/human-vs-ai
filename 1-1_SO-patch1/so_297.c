    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, const char * argv[]) {
            int histogram[10000] = {0};
            int i;
    
            int *rectPtr = histogram;
                    int size = 0;
                    int retval = 0;
    
            printf("Enter the number of elements \n");
            while (  (retval = scanf("%d", &size)) != EOF && (retval == 1)) {
                    rectPtr = histogram;
                            if (!size) return 0;
                            printf("Enter %d elements\n", size);
                            for (i = 0; i < size; ++i) {
                                    scanf("%d", rectPtr);   //check in a simmilar way to above
                                    rectPtr++;
                            }
                    printf("%d\n", 1111111);
    
            printf("Enter the number of elements: \n");
            }
            return 0;
    }