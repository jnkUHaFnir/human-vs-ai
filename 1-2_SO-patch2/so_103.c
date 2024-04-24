    FLIGHT_ENTRY_TYPE newEntry;
    int len = sizeof(FLIGHT_ENTRY_TYPE)*2;// *2 to account for comma delimiters, etc.  Change as needed
    char **stringArray = {0};
    //see edits in answer below for defintion of allocArray()
    stringArray = allocMemory(stringArray, MAX_PLANES_IN_A_FLIGHT, len);    FILE *fp = fopen(".\\filename.bin", "rb");
    if(fp)
    {   
        while(fgets(stringArray[i], len, fp)
        {
             fresult = sscanf(line, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n",
                        &plocalx,
                        &plocaly,
                        &plocalz,
                        &ppitch,
                        &proll,
                        &pheading,
                        &pgearpos,
                        &pflappos,
                        &pbrakepos,
                        &pcanopypos,
                        &pafterburnon,
                        &pkias,
                        &ptime);  
              if(fresult > 0)
              { ...assign values to newEntry struct...  }
    
        }
    }