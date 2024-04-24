do {
    printf("Enter lower bound row: ");
    l_boundRow  = getBoundary(l_boundRow);

    if (!checkStr(l_boundRow)) { // if the string is invalid, the program asks user if they want to try again
        if (doAgain())
            continue;
    } else {
        break; // break out of the loop when the input is valid and user chooses not to try again
    }
} while (1);
