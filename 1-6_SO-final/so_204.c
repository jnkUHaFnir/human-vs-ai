    #include <stdio.h>
    int main(void) {
	    int tek;
	    int radica[50];
	    // open file
	    FILE *myFile = fopen("numbers.txt", "r");
	    // if opening file fails, print error message and exit 1
	    if (myFile == NULL) {
		    perror("Error: Failed to open file.");
		    return 1;
	    }
	    // read values from file until EOF is returned by fscanf
	    for (int i = 0; i < 50; ++i) {
		    // assign the read value to variable (tek), and enter it in array (radica)
		    if (fscanf(myFile, "%d", &tek) != EOF) {
			    radica[i] = tek;
		    } else {
			    break; // if EOF is returned by fscanf, break loop
		    }
	    }
	    // close file
	    fclose(myFile);
	    return 0;
    }