scanf("%ld", &offset_ed);  // Get the offset from the user.
fseek(f, offset_ed, SEEK_SET);

printf("Specify HEX bytes to be written to the binary: ");
scanf("%s", hexes);  // Read the input as a string.

size_t num_bytes = strlen(hexes) / 2;  // Calculate the number of bytes to be written.

for (size_t i = 0; i < num_bytes; i++) {
  unsigned int byte;
  sscanf(hexes + (2 * i), "%2X", &byte);  // Read 2 characters as a hexadecimal byte.
  fwrite(&byte, sizeof(unsigned char), 1, f);  // Write the byte to the file.
}
fclose(f);
