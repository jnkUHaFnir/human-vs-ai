char hexes[10]; // Make sure it's large enough to hold the bytes you are going to input

scanf("%ld", &offset_ed); // Get the offset from the user
fseek(f, offset_ed, SEEK_SET);

printf("Specify HEX bytes to be written to the binary: ");
scanf("%s", hexes); // Read the hex instructions as a string

// Convert the hex string to actual bytes
unsigned char bytes[sizeof(hexes)/2];
for(int i = 0; i < sizeof(hexes)/2; i++) {
    sscanf(hexes + 2*i, "%2hhx", &bytes[i]);
}

fwrite(bytes, sizeof(unsigned char), sizeof(hexes)/2, f); // Write the bytes to the file

fclose(f);
