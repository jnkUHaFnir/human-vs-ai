for (int i = 0; i < MAX_FLIGHT_ENTRIES; i++)
{               
    FLIGHT_ENTRY_TYPE newEntry;

    int fresult = fscanf(pFile, "%lf %lf %lf %f %f %f %f %f %f %f %f %f %f",
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

    if (fresult == 13) // Check if all 13 values were successfully read
    {
        FlightEntries[fileIndex][i] = newEntry;
    }
    else if (fresult == EOF) // Handle end of file
    {
        FlightInfo[fileIndex].endFrameIndex = i - 1;
        break;
    }
    else // Handle the case where fscanf did not read all values
    {
        printf("Error reading data from file at entry %d\n", i);
        break;
    }
}
