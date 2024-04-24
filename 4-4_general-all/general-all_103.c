#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHT_ENTRIES    27000
#define MAX_PLANES_IN_A_FLIGHT 10

typedef struct {
    double local_x;
    double local_y;
    double local_z;
    float pitch;
    float roll;
    float heading;
    float gearpos;
    float flappos;
    float speedbrakepos;
    float canopypos;
    float afterburnerOn;
    float kias;
    float time;     // record timestamp
} FLIGHT_ENTRY_TYPE;

static FLIGHT_ENTRY_TYPE FlightEntries[MAX_PLANES_IN_A_FLIGHT][MAX_FLIGHT_ENTRIES];

int main() {
    FILE *pFile = fopen("your_file.txt", "r");
    if (pFile == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int fileIndex = 0;
    int i;
    for (i = 0; i < MAX_FLIGHT_ENTRIES; i++) {
        FLIGHT_ENTRY_TYPE newEntry;
        if (fscanf(pFile, "%lf%lf%lf%f%f%f%f%f%f%f%f%f%f", 
                    &newEntry.local_x, &newEntry.local_y, &newEntry.local_z,
                    &newEntry.pitch, &newEntry.roll, &newEntry.heading,
                    &newEntry.gearpos, &newEntry.flappos, &newEntry.speedbrakepos,
                    &newEntry.canopypos, &newEntry.afterburnerOn, &newEntry.kias, &newEntry.time) == 13) {
            // Data read successfully, allocate memory for FlightEntries[fileIndex][i]
            FlightEntries[fileIndex][i] = newEntry;
        } else {
            fprintf(stderr, "Error reading data from file\n");
            break;
        }
    }

    fclose(pFile);

    return 0;
}
