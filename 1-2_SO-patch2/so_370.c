    while (fscanf(fPtr, "%s %lf", x, &y) == 2)
    {
        // Successfully scanned a string and a double from the file
        fprintf(stdout, "Value read = %s\n", x);
        fprintf(stdout, "GPA = %lf \n", y);
    }