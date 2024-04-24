int num; // variable to store the return value of scanf

for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
        num = scanf("%d", &arr[i][j]);
        
        if (num != 1) {
            printf("insufficient datapoints\n");
            break;
        }
    }
 }
