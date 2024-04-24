char sign, before_dot;
int mantissa;
int exponent;

// Reading the line with fscanf
fscanf(file_pointer, "%c%d.%dE%03d;", &sign, &before_dot, &mantissa, &exponent);
