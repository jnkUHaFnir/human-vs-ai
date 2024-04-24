// Change this line
// fgets(buffer, BUFFSIZE, stdin);
// to
fgets(buffer, BUFFSIZE, file);
if (fgets(buffer, BUFFSIZE, file) == NULL) {
    break; // End of file reached
}
