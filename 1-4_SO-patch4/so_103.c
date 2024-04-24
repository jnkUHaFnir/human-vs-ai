    FLIGHT_ENTRY_TYPE newEntry;
    int len = sizeof(FLIGHT_ENTRY_TYPE) + 1;
    char line[len];
    FILE *fp = fopen(".\\filename.bin", "rb");
    if(fp)
    {   
        while(fgets(line, len, fp)
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