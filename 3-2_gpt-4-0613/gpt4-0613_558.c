Note that the choice to use a switch statement is just to make the code cleaner. The if / else if statements you had would work just as well.

However, do note that atoi() doesn't return an error if the conversion fails—it just silently returns 0.

For more robust error checking, you may want to use another function, like strtol(), which allows you to detect errors during conversion, or even write your function to verify if the string can be converted to an integer.
