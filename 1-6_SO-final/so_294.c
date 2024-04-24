    #include <stdio.h>
    
    #define MAX_COLOR_STR_LEN 10
    
    int valueFromColor(char const * const color) 
    {
      if(strcmp("green", color))
        return 2;
      if(strcmp("red", color))
        return 3;
    }
    int main()
    {
        char bands;
        char color1[MAX_COLOR_STR_LEN];
        char color2[MAX_COLOR_STR_LEN];
        int mult;
        
        
        printf("Select how many bands the resistor has");
        printf("\n A. 4 bands");
        printf("\n B. 5 bands");
        printf("\n C. 6 bands");
        scanf("%c", &bands);
        
        switch (bands)
        
        case 'a':
        case 'A':
          printf("Enter the colors");
          scanf("%s %s", color1, color2);
          mult = valueFromColor(color1) * valueFromColor(color2);
          printf("%d", mult);
        
        getchar();
        return 0;
    }