int scanResult;
do
{
  scanResult = scanf("%d", &numOfDef);
  while(getchar() != '\n'); // clear input buffer

  if(scanResult != 1)
    printf("This is not a number. Try again.\n");
    
  else if(numOfDef <= 0)
    printf("This is not a positive number. Try again.\n");
   
} while(scanResult != 1 || numOfDef <= 0);
```  

This code performs the following steps:

- Checks if the input is successfully scanned as an integer.
- Clears the input buffer to remove any excess characters.
- If the input is not an integer, it requests the user to input a number.
- If the number is not positive, it requests the user to input a positive number.
- It continues to do the above steps until a positive number is successfully scanned.
