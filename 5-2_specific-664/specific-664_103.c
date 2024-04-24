for (int i = 0; i < MAX_FLIGHT_ENTRIES; i++)
{               
    // If the file end is found before it should be, set values to defaults
    // and save the file
    if (feof(pFile))
    {
        FlightInfo[fileIndex].endFrameIndex = i - 1;
        break;
    }
    else
    {
        FLIGHT_ENTRY_TYPE newEntry;

        if (fscanf(pFile, "%lf %lf %lf %f %f %f %f %f %f %f %f %f %f\n",
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
            &newEntry.time) == 13) // Check if all fields were successfully read

        FlightEntries[fileIndex][i] = newEntry;
    }
}
