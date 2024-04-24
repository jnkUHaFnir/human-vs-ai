#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char surname[MAX_LEN];
  char UUN[MAX_LEN];
  char department[MAX_LEN];
  char gender;
  int age;
} student_t;

int main(void)  {
  int i;
  student_t student[6];

  // No changes above here except variable name
  //...

  for (i = 3; i < 6; i++) {
    printf("Enter your name: ");
    scanf("%99s", student[i].name);
    printf("Enter your surname: ");
    scanf("%99s", student[i].surname);
    printf("Enter your UUN: ");
    scanf("%99s", student[i].UUN);
    printf("Enter your department: ");
    scanf("%99s", student[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student[i].gender); // the space before %c is to consume any whitespace before reading in for .gender 
    printf("Enter your age: ");
    scanf(" %d", &student[i].age);
  }

  return EXIT_SUCCESS;
}
