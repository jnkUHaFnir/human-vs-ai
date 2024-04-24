In this method, `YY_INPUT` is called when lex needs more input. Each time it's called, it will read an entire line (or as much of a line as can fit into its buffer), and then make sure that the `line` string contains a copy of that line.

And when a parsing error occurs, you can print that line like:
```C
yyerror(const char *msg) {
    fprintf(stderr, "Error: %s at line: %s\n", msg, line);
}
