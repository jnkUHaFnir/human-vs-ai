char sign, mantissa_int[2], mantissa_frac[7], exponent[3];

sscanf(line, "%c%1[0-9].%6[0-9E-]%3[E]", &sign, mantissa_int, mantissa_frac, exponent);

// Now you have the sign, mantissa integer part, mantissa fractional part, and the exponent
