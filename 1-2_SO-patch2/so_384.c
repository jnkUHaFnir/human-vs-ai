	#include <stdio.h>
	int main(int argc, char *argv[]) {
		unsigned int count;	 // number of numbers to scan
		printf("How many integers do you want to insert? "); // output for the user
		scanf ("%d", &count); // input number count of the user
		unsigned int indexOfNumber; // for index, declared outside because of output at the end
		double highestNumber; // saving the highest value in a helper variable
		for (indexOfNumber = 1; indexOfNumber <= count; indexOfNumber++) {
			printf("Input number %d: ", indexOfNumber); // output for the user
			
			double scannedNumber;
		    scanf("%lf", &scannedNumber); // input a number of the user
		    if (indexOfNumber == 1 || scannedNumber > highestNumber) {
				highestNumber = scannedNumber;
			}
		}
		printf("Highest input number on index %d, the value is %.2lf", indexOfNumber, highestNumber);
		return 0;
	}