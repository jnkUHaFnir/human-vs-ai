    hypo_table[0][0] = fopen("00.txt", "w");
    hypo_table[1][0] = fopen("10.txt", "w"); //Here ,it is 01 
    hypo_table[2][0] = fopen("20.txt", "w"); //Here ,it is 02 
    hypo_table[3][0] = fopen("30.txt", "w"); //Here ,it is 03
    
    hypo_table[1][0] = fopen("10.txt", "w"); //Here You are reopening
    hypo_table[1][1] = fopen("11.txt", "w");
    hypo_table[1][2] = fopen("12.txt", "w");
    hypo_table[1][3] = fopen("13.txt", "w");
  