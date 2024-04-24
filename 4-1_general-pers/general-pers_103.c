#include <stdio.h>

// Define struct and array as you have done

int main() {
    FILE *pFile = fopen("your_file.txt", "r");
    if (!pFile) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < MAX_FLIGHT_ENTRIES; i++) {
        FLIGHT_ENTRY_TYPE newEntry;
        
        if (fscanf(pFile, "%lf %lf %lf %f %f %f %f %f %f %f %f %f %f",
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
            &newEntry.time) != 13) {
            fprintf(stderr, "Error reading values from file at entry %d\n", i);
            break;
        }

        memcpy(&FlightEntries[fileIndex][i], &newEntry, sizeof(FLIGHT_ENTRY_TYPE));
    }

    fclose(pFile);
    return 0;
}
