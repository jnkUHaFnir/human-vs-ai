double d = ...;  // the floating point number
int intPart = (int)d;
int numDigitsIntPart = snprintf(NULL, 0, "%d", intPart);
int fractionalPrecision = 16 - numDigitsIntPart - 1;  // minus 1 for the dot
if (fractionalPrecision < 0) fractionalPrecision = 0;
char format[10];
sprintf(format, "%%.%df", fractionalPrecision);
char output[17];
snprintf(output, sizeof(output), format, d);
char output[17];
snprintf(output, sizeof(output), "%.15f", d);
char output[17];
int chars_written = snprintf(output, sizeof(output), "%.15f", d);
if (chars_written >= sizeof(output)) {
  snprintf(output, sizeof(output), "%.14e", d);
}
