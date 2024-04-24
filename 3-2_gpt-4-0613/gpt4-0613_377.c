
In this updated version of your program, I added a variable `count` to count the number of valid (not -99) temperatures entered by the user. So, the average is calculated using `count` instead of `SIZE`.

Also, I inserted a condition to break the loop if `temp` equals to -99. If -99 is entered, the program will immediately stop asking for more temperatures.

The code `(count == 0) ? 0 : (double) sum/count` is necessary to avoid a division by zero in case the user inputs -99 as the first temperature. This piece of code uses the conditional (ternary) operator `? :` to return 0 if `count` is 0. Otherwise, it calculates the average normally.
