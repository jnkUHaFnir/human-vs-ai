char Grade[3]; // to hold grades like A-, B+, etc.
strcpy(Grade, "A-"); // assign A- to Grade
if(x>=80)
    Grade = 'A';
else if(x>=75) // minus represented by '1'
    Grade = 'A1'; 
else if(x>=70)
    Grade = 'B';
else if(x>=65) // minus represented by '1'
    Grade = 'B1';
else if(x>=60)
    Grade = 'B2';
// and so on
