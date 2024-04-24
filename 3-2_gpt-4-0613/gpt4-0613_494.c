
In this version, Grade is now an array of characters (a short string, in other words). Arrays can hold multiple values, so now you can store grades that are more than one character long (like "A-", "B+", etc.).

In place of assignment, I used `sprintf` function which is used to write formatted output to the string. Format tags `%s` is used for string and `sprintf` writes to the Grade string.
