unsigned char hexes[10]; // Assuming maximum 10 bytes of hex instructions

// ...

printf("Specify HEX bytes to be written to the binary:  ");
scanf("%s", hexes); // Read the hex instructions as a string

int numBytes = strlen(hexes) / 2;  // Calculate the number of bytes (2 characters per byte)

unsigned char byte; // Temporary variable to hold each byte

// Convert the hex string to actual bytes
for (int i = 0; i < numBytes; i++) {
    sscanf(hexes + i*2, "%2hhx", &byte);  // Read 2 characters from the hex string and convert to byte
    hexes[i] = byte; // Store the byte in the array
}

// Write the bytes to the file
fwrite(hexes, sizeof(unsigned char), numBytes, f);
