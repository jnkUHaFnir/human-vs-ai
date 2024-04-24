for (i = 0; i < MAX_FLIGHT_ENTRIES; i++)
{
    // allocate memory for each entry
    FlightEntries[fileIndex][i] = malloc(sizeof(FLIGHT_ENTRY_TYPE));

    // read data from file
    // ...

    // create newEntry and copy data
    // ...

    // use memcpy to copy the data into the array
    memcpy(FlightEntries[fileIndex][i], &newEntry, sizeof(FLIGHT_ENTRY_TYPE);
}
// free memory for each entry
for (i = 0; i < MAX_FLIGHT_ENTRIES; i++)
{
    free(FlightEntries[fileIndex][i]);
}
