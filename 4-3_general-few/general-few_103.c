for (i = 0; i < MAX_FLIGHT_ENTRIES; i++) {
    if (feof(pFile)) {
        FlightInfo[fileIndex].endFrameIndex = i - 1;
        break;
    } else {
        // Read data from file into temporary variables
        float plocalx, plocaly, plocalz, ppitch, proll, pheading, pgearpos, pflappos, pbrakepos, pcanopypos, pafterburnon, pkias, ptime;
        int fresult;
        fresult = fscanf(pFile, "%f %f %f %f %f %f %f %f %f %f %f %f %f\n", &plocalx, &plocaly, &plocalz, &ppitch, &proll, &pheading, &pgearpos, &pflappos, &pbrakepos, &pcanopypos, &pafterburnon, &pkias, &ptime);

        // Update FlightEntries element
        FlightEntries[fileIndex][i].local_x = (double)plocalx;
        FlightEntries[fileIndex][i].local_y = (double)plocaly;
        FlightEntries[fileIndex][i].local_z = (double)plocalz;
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
    }
}
