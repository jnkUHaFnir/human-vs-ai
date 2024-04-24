    if (scount == 0)
    {
        s = (students*)malloc(sizeof(students));
    }
    else
    {
        s = realloc(s, sizeof(students) * scount); // You missed the re-assignment
    }