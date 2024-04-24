#include <stdio.h>

int main() {
    int departures[] = {480, 585, 679, 767, 840, 945, 1140, 1185};
    int arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int hours, minutes, user_time, closest_dep_time, closest_arr_time, min_diff = 1440; // 1440 is the total minutes in one day

    printf("Enter a 24 hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    user_time = hours * 60 + minutes;

    for (int i = 0; i < 8; i++) {
        int diff = user_time - departures[i];
        if (diff < 0) {
            diff = -diff;
        }
        if (diff < min_diff) {
            min_diff = diff;
            closest_dep_time = departures[i];
            closest_arr_time = arrivals[i];
        }
    }

    printf("Closest departure time is %02d:%02d ", closest_dep_time / 60, closest_dep_time % 60);
    if (closest_dep_time < 720) {
        printf("am");
    } else {
        printf("pm");
    }
    printf(", arriving at %02d:%02d ", closest_arr_time / 60, closest_arr_time % 60);
    if (closest_arr_time < 720) {
        printf("am");
    } else {
        printf("pm");
    }

    return 0;
}
