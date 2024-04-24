for (i = 0; i < MAX_FLIGHT_ENTRIES; i++)
{               
    if (feof(pFile))
    {
        FlightInfo[fileIndex].endFrameIndex = i - 1;
        break;
    }
    
    FLIGHT_ENTRY_TYPE newEntry;

    fscanf(pFile, "%lf %lf %lf %f %f %f %f %f %f %f %f %f %f\n",
           &newEntry.local_x,
           &newEntry.local_y,
           &newEntry.local_z,
           &newEntry.pitch,
           &newEntry.roll,
           &newEntry.heading,
           &newEntry.gearpos,
           &newEntry.flappos,
           &newEntry.speedbrakepos,
           &newEntry.canopypos,
           &newEntry.afterburnerOn,
           &newEntry.kias,
           &newEntry.time);

    FlightEntries[fileIndex][i] = newEntry;
}
