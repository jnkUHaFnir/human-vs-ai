    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>    // Include the iostream for cin
    
    int main (void)
    {
    int menu_selection,error_flag,repeater;
    float force, area, pressure;
    
    printf("Please select a formula. [0 - 3]\n>>");
    scanf("%d",&menu_selection);
    if(menu_selection==1)
        {
        error_flag=0;
        system("cls"); 
    
        printf("Pressure's formula\n\n");
            do{
                error_flag=0;
                printf("Please key in the force applied.(N)\n>>");
                std::cin >> force;                     // Read value into force
                if(cin && force>=0)                  // Verify the force is of type float. cin will set its failbit if the user does not input the proper data type.
                {
                    printf("Please key in the surface area.(m^2)\n>>");
                    scanf("%f",&area);
    
                    pressure = force/area;
    
                    printf("The pressure is %.2fPa.\n\n",pressure);
                }
                else
                {
                    error_flag=1;
                    printf("Invalid input, please key in a positive number.");
                }
            }while(error_flag==1);
        }
        return 0;
    }