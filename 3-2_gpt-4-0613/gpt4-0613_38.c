
In this code `strcspn(input, "\n")` gives the index of newline character in input string, and then we are replacing newline character with NULL character i.e., terminating the string before newline. 

In the for loop, Instead of checking for '\0' inside for loop(last character of string), null character is added after loop. This makes the loop-simple and improves readability.
