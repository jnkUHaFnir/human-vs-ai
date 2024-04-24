temporary = realloc(buffer, length + 1001);
if (temporary != NULL) {
    buffer = temporary; // Now both buffer and temporary point to the same memory block
}
else {
    printf("Error: Out of memory!\n");
    free(temporary); // Double free here
    free(buffer); // This free is valid
    return 1;
}
