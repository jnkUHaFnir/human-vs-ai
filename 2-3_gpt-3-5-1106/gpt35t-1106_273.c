char sign;
int before_dot;
int between_dot_exponent;
int exponent;
fscanf(file, "%c%*d.%dE%d;%*d;%c", &sign, &before_dot, &between_dot_exponent, &exponent);
