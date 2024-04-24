    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    main() {
        int month;
        printf("Insert the number of the month and the program will return its name");
        scanf("%i", &month);
        assert((month <= 0 || month > 12) && "invalid month value"); 
        switch (month) {
            case (1):
                printf("The month is January");
                break;
            case (2):
                printf("The month is February");
                break;
               
               //continues 
               
            case (12):
                printf("The month is December");
                break;
            default:
                assert(0 && "not valid month");
          }
          system("pause");
          return 0;
    }