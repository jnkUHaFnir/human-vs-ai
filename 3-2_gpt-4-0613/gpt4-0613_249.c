
do {
    printf("Enter lower bound row: ");
    l_boundRow  = getBoundary(l_boundRow);

    if (!checkStr(l_boundRow)) {   // Check the string, if its invalid then ask if user wants to try again
        if(doAgain())
           continue;
        else
           break;
    }
    else
        break;
} while (1);

// The above change, ensures that your doAgain function is called everytime checkStr(l_boundRow) 
// function fails. And also if user does not want to try again the loop breaks.

free(l_boundRow);
return 0;
