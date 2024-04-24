char result[1000]; // Assuming a maximum length for the final string
strcpy(result, ""); // Initialize result as an empty string

// .. build string out of variable-length data
for (int i = 0; i < length_of_data; i++) {
    char temp[100]; // Assuming a maximum length for the individual strings
    sprintf(temp, "%d", variable_length_data[i]); // Convert data to string
    strcat(result, temp); // Append the string to the result
}

// .. some parts are conditional
if (freezeCount < 0) strcat(result, "]");
else strcat(result, ")");
