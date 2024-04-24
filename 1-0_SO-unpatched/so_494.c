    size_t index;
    if(x < 25)    // Safety measure
    {
        index = 0; // F
    }
    else if (x > 79) // [edit] ok we need another one
    {
        index = 11; // A (or should it be A+ ?)
    }
    else // The real trick
    {
        index = (x/5 + 1) - 6 ;
    }
    // You need 3 chars: one for the letter, one for the + (or -) and the
    // last one for the NULL-terminating '\0' which is the "end-of-string" byte
    char student_grade[3];
    strcpy(student_grade, grades[index]);