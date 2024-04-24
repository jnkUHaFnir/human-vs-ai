char Grade[3]; // Change Grade to char array to store grades

if(x<=100 && x>=80)
    strcpy(Grade, "A");
else if(x<=79 && x>=75)
    strcpy(Grade, "A-");
else if(x<=74 && x>=70)
    strcpy(Grade, "B+");
// Continue for all grades

printf("%s have the following marks %d and the Grade is %s\n ", studentName, x, Grade);
