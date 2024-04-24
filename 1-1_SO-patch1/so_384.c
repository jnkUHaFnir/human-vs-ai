		#include <stdio.h>
	int main(int argc, char *argv[]) {
		signed int count = 0;	 // number of numbers to scan
		
		
		while (count < 1) {
			printf("How many integers do you want to insert? "); // output for the user
			scanf ("%d", &count); // input number count of the user
			if (count < 1) {
				printf("You entered a negative number or zero. Please enter a number >0 \n"); // output for the user
			}
		}
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
		printf("Highest input number on index %d, the value is %.2lf\n", indexOfNumber-1, highestNumber);
		return 0;
	}