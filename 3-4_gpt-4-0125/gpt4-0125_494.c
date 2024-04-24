#include<stdio.h>

int main()
{
    int count=0;
    int x;
    char Grade[3]; // Change to a char array to hold more than one character including the '\0' (null terminator)
    char studentName[50];
    int studentID=0;
    int f=0;

    do
    {
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if(studentID!=0)
        {           
            printf("Enter student name: ");
            scanf("%s", studentName); // The & is not needed for array types as they are already passed as references
            printf("Enter student marks: ");
            scanf("%d", &x);

            if(x<=100 && x>=80)
                strcpy(Grade, "A"); // Use strcpy to copy the string into the Grade array
            else if(x<=79 && x>=75)
                strcpy(Grade, "A-");
            else if(x<=74 && x>=70)
                strcpy(Grade, "B+");
            else if(x<=69 && x>=65)
                strcpy(Grade, "B");
            else if(x<=64 && x>=60)
                strcpy(Grade, "B-");
            else if(x<=59 && x>=55)
                strcpy(Grade, "C+");
            else if(x<=54 && x>=50)
                strcpy(Grade, "C");
            else if(x<=49 && x>=45)
                strcpy(Grade, "C-");
            else if(x<=44 && x>=40)
                strcpy(Grade, "D+");
            else if(x<=39 && x>=35)
                strcpy(Grade, "D");
            else if(x<=34 && x>=30)
                strcpy(Grade, "D-");
            else if(x<=29 && x>=0)
            {
                strcpy(Grade, "F"); 
                f++;
            }   
            printf("%s have the following marks %d and the Grade is %s\n ", studentName, x, Grade); // Change %c to %s
            count++;        
        }   
    }while(studentID!=0);

    printf("Sum of student =  %d\n", count);
    printf("Sum of fail student = %d\n", f);
}
