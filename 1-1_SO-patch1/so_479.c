    #include <stdio.h>
    #include <string.h>
    void bufferClean(char *buff); // please see the note below the code
    
    int main()
    {
        char newInvoice[1];
        do 
        {
            scanf("%s", newInvoice);
            bufferClean(&buffer);  // please see the note below the code
            if (newInvoice[0] == 'Y' || newInvoice[0] == 'y') 
            {
                printf("you've chosen YES, continue ......\n");
                break;
            }
            else if (newInvoice[0] == 'N' || newInvoice[0] == 'n')
            {
                printf("you've chosen NO, Goodbye!\n");
                return 1;
            }
            else 
            {
                printf("Invalid Entry (it has to be y or n):\n");
            }
        } while(1);
    
        printf("exited the loop\n");
        return 0;
    }