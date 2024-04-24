float num;
int sign, digits, exponent;

sscanf(line, "%f;", &num);

if(num >= 0) {
    sign = 1; // positive number
} else {
    sign = -1; // negative number
    num = -num; // change sign to positive for further processing
}

digits = (int)(num * 1000000); // get the digits between dot and exponent

exponent = 0;
if(num != 0) {
    while(num < 1) {
        num *= 10;
        exponent--;
    }
    while(num >= 10) {
        num /= 10;
        exponent++;
    }
}
