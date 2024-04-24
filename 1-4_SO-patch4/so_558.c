    void flushInput(){
      char c;
      while((c = getchar()) != '\n' && c != EOF)
    		/* discard */ ;  
    }
    
    int menu() {            // prints the main menu of labs///
        int choice;
        printf("1)Lab 5 ( Repetetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
        if(scanf("%d", &choice) != 1){
            flushInput();
            return 0;
        }
        return choice;
    }