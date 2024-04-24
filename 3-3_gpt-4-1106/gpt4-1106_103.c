// Read values from file
int fresult = fscanf(...);

// Check the result of reading
if (fresult != 13)
{
    if (feof(pFile))
    {
        // Handle end-of-file, break the loop
        ...
    }
    else
    {
        // Handle reading/format error, might want to break or handle error
        ...
    }
}
FlightEntries[fileIndex][i].local_x = (double)plocalx;
FlightEntries[fileIndex][i].local_y = (double)plocaly;
FlightEntries[fileIndex][i].local_z = (double)plocalz;
// Set the rest of the members similarly...
