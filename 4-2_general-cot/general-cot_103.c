#include <stdio.h>

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

void readFlightData(FILE* pFile, int fileIndex) {
    for (int i = 0; i < MAX_FLIGHT_ENTRIES; i++) {
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
            &newEntry.time) == 13) { // Check if all values were read successfully
            FlightEntries[fileIndex][i] = newEntry;
        } else {
            // Error handling if fscanf fails to read all values
            printf("Error reading data from file.\n");
            // Handle the error or break the loop
            break;
        }
    }
}

int main() {
    // Open your file for reading
    FILE* pFile = fopen("file.txt", "r");
    if (pFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    readFlightData(pFile, 0); // Assuming fileIndex is 0

    // Close the file when done
    fclose(pFile);

    return 0;
}
