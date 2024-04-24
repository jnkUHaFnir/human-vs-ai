char sign;
int intPart;
int mantissa;
int exponent;

sscanf(numberString, "%c%d.%dE%*c%d", &sign, &intPart, &mantissa, &exponent);
