#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int enter(int MeasurmentData[])
{	
	char input[1000];
	int nrMeasurement = 0;
	
	// reseting Measurment data
	for(int i=0;i<10;++i) MeasurmentData[i] = 0;
	
    for(int i=0;i<10;++i) 
    {
        scanf("%s", input);
		if(strcmp(input, "q") == 0) {
			break;
		}
		MeasurmentData[i] = (int) strtol(input, (char **)NULL, 10);
		nrMeasurement++;
    }
	
	return nrMeasurement;
}
void showMeasurments(int* MeasurmentData, int length) {
	int i = 0;
	
	printf(" ======== Measurment ======== \n");
	
	for(i = 0; i < length; i++) {
		printf("%d ", MeasurmentData[i]); 
	}
	
	printf("\n");
}
int main()
{
	int MeasurmentData[10];
    int nrOfmeasurments;
    char menuoption;
    while (1) 
    {
        printf("Measurment tool 2.0\n" "v (View)\n" "e (Enter)\n" "c (Compute)\n" "r (Reset)\n" "q (Quit)\n enter your option:\n");
        scanf(" %c", &menuoption);
        if (menuoption =='e') // enter values
        {
            enter(MeasurmentData);
        }
        else if(menuoption == 'v') // view values
        {
			// show
			showMeasurments(MeasurmentData, 10);
        }
        else if(menuoption == 'c')
        {
        }
        if(menuoption == 'q')
        {
			printf("Exiting Measurment tool 2.0\n");
			break; 
        }
    }
	
	return 0;
}
Edit: i have updated the code. So i have read the comments of your question and there you have explained a little better what you are trying to accomplish. So since you have the requirement to press 'q' to stop reading values. I have to read all measurments as string and convert to integer if it is not the character q.
Edit 2: Thanks to @user3629249 to point out some of the flaws from the code ill update with his suggestions.