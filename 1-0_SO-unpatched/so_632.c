    char buffer[100];
    int bytesRead = fgets(buffer, 100, p_finput);
    int itemsScanned = 0;
    if(bytesRead > 0){
        itemsScanned = sscanf(buffer, "%d", &a);
    }
    /* check itemsScanned & continue */