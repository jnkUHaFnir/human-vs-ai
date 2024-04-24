    size_t index;
    if(x < 4)    // Safety measure
    {
        index = 0;
    }
    else // The real trick
    {
        index = (x/5 + 1) - 6 ;
    }
    // You need 3 chars: one for the letter, one for the + (or -) and the
    // last one for the NULL-terminating '\0' which is the "end-of-string" byte
    char student_grade[3];
    strcpy(student_grade, grades[index]);