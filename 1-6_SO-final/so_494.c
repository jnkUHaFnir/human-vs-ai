    size_t index;
    if(x < 4)    // Safety measure
    {
        index = 0;
    }
    else // The real trick
    {
        index = (x/5 + 1) - 6 ;
    }
    strcpy(Grade, grades[index]);