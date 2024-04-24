%[+-]%*[0-9].%*[0-9]E%[+-]%*[0-9]
char number[30] = "+6.590472E-01;+2.771043E+07;+";
char sign, dot_digit, exponent_sign;
int dot_number, exponent_number;

// Assuming 'number' contains the desired number
sscanf(number, "%*[0-9.]%c%*[0-9.]E%c%*[0-9]", &dot_digit, &exponent_sign);
sscanf(number, "%c%*[0-9.]%c%*[0-9.]E%c%*[0-9]", &sign, &dot_digit, &exponent_sign);
sscanf(number, "%c%d.%*[^E]E%c%*[0-9]", &sign, &dot_number, &exponent_sign);

printf("Sign: %c\n", sign);
printf("Dot Digit: %c\n", dot_digit);
printf("Dot Number: %d\n", dot_number);
printf("Exponent Sign: %c\n", exponent_sign);
