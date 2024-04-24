static string printInt(Object self) {
    char temp[20]; // Assuming a max of 20 digits for unsigned long
    string str;

    snprintf(temp, 20, "%lu", getValueInt(self));
    str = (string)GC_MALLOC(strlen(temp) + 1);

    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Handle allocation failure as needed
    }

    strcpy(str, temp);

    return str;
}
