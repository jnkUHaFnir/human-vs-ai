if (pFile != NULL) {
    for ( i = 0; i < MAX_FLIGHT_ENTRIES; i++)
    {               
        if (feof(pFile))
        {
            FlightInfo[fileIndex].endFrameIndex = i - 1;
            break;
        }
        else
        {
            double plocalx, plocaly, plocalz;
            float ppitch, proll, pheading, pgearpos, pflappos, pbrakepos, pcanopypos, pafterburnon, pkias, ptime;

            int fresult;
            fresult = fscanf(pFile, "%lf %lf %lf %f %f %f %f %f %f %f %f %f %f\n",
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
                                        
            if(fresult == 13) {
                FlightEntries[fileIndex][i].local_x = plocalx;
                FlightEntries[fileIndex][i].local_y = plocaly;
                FlightEntries[fileIndex][i].local_z = plocalz;
                FlightEntries[fileIndex][i].pitch = ppitch;
                FlightEntries[fileIndex][i].roll = proll;
                FlightEntries[fileIndex][i].heading = pheading;
                FlightEntries[fileIndex][i].gearpos = pgearpos;
                FlightEntries[fileIndex][i].flappos = pflappos;
                FlightEntries[fileIndex][i].speedbrakepos = pbrakepos;
                FlightEntries[fileIndex][i].canopypos = pcanopypos;
                FlightEntries[fileIndex][i].afterburnerOn = pafterburnon;
                FlightEntries[fileIndex][i].kias = pkias;
                FlightEntries[fileIndex][i].time = ptime;
            } else {
                printf("fscanf error on row %d - Return value: %d\n", i, fresult);
                break;
            }
        }
    } 
} else {
    printf("Unable to open file\n");
}
