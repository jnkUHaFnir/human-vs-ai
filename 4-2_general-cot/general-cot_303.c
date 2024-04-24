#include <stdio.h>

int main() {
    // Flight departure times since midnight
    int departureTimes[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int arrivalTimes[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int hours, minutes, userTime, closestDepTime, closestArrTime, timeDiff, minDiff = 1441; // 24 hours * 60 minutes

    // Get the user's time
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);
    userTime = hours * 60 + minutes;

    // Find the closest departure time
    for (int i = 0; i < sizeof(departureTimes) / sizeof(departureTimes[0]); i++) {
        timeDiff = userTime - departureTimes[i];
        if (timeDiff >= 0 && timeDiff < minDiff) {
            minDiff = timeDiff;
            closestDepTime = departureTimes[i];
            closestArrTime = arrivalTimes[i];
        }
    }

    // Display the closest departure and arrival times
    printf("Closest departure time is %02d:%02d", closestDepTime / 60, closestDepTime % 60);
    if (closestDepTime < 720) {
        printf("am");
    } else {
        printf("pm");
    }
    printf(", arriving at %02d:%02d", closestArrTime / 60, closestArrTime % 60);
    if (closestArrTime < 720) {
        printf("am");
    } else {
        printf("pm");
    }

    return 0;
}
