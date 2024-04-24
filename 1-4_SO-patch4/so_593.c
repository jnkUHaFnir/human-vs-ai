#include <stdio.h>
void enter(int MeasurmentData[])
{	
    for(int i=0;i<10;++i)
    {
        scanf("%d", &MeasurmentData[i]);
    }
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
        printf("Measurment tool 2.0\n");
        printf("v (View)\n");
        printf("e (Enter)\n");
        printf("c (Compute)\n");
        printf("r (Reset)\n");
        printf("q (Quit)\n");
        printf("enter your option:\n");
        scanf("%c", &menuoption);
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