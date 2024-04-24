#include<stdio.h>
#include<string.h>

int main()
{
    int count=0;
    int x;
    char Grade[3];
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
            scanf("%s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if(x>=80)
                strcpy(Grade, "A");
            else if(x>=75)
                strcpy(Grade, "A-");
            else if(x>=70)
                strcpy(Grade, "B+");
            // ... continue with the rest of the grades

            if(x>=0 && x<=100)
            {
                printf("%s has the following marks %d and the Grade is %s\n", studentName, x, Grade);
                count++;
                if(strcmp(Grade, "F") == 0)
                {
                    f++;
                }
            }
            else
            {
                printf("Invalid marks\n");
            }
        }   
    }while(studentID!=0);

    printf("Sum of student =  %d\n", count);
    printf("Sum of fail student = %d\n", f);
}
