#include <stdio.h>
#include <stdlib.h>

#define LGT 30

struct profile {
    int pl_num;
    char name[LGT];
    char lname[LGT];
    int atbat;
    int hits;
    int walks;
    int runs;
    float batavg;
};

int main(void)
{
    FILE *flx;
    int i;
    struct profile stat[19] = {0}; // Assuming player numbers are in the range 0-18

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team.txt!\n");
        exit(1);
    }

    while (fscanf(flx, "%d %s %s %d %d %d %d", &i, stat[i].name, stat[i].lname, &stat[i].atbat, &stat[i].hits, &stat[i].walks, &stat[i].runs) == 7) {
        stat[i].pl_num = i; // Assign player number

        // Calculate batting average
        if (stat[i].atbat > 0) {
            stat[i].batavg = (float)stat[i].hits / stat[i].atbat;
        }

        // Print player's stats for each game
        printf("Player %d - %s %s\n", i, stat[i].name, stat[i].lname);
        printf("At Bats: %d, Hits: %d, Walks: %d, Runs: %d\n", stat[i].atbat, stat[i].hits, stat[i].walks, stat[i].runs);
        printf("Batting Average: %.3f\n\n", stat[i].batavg);
    }

    fclose(flx);

    // Calculate cumulative statistics for the entire team
    int total_atbats = 0, total_hits = 0, total_walks = 0, total_runs = 0;
    for (i = 0; i < 19; i++) {
        total_atbats += stat[i].atbat;
        total_hits += stat[i].hits;
        total_walks += stat[i].walks;
        total_runs += stat[i].runs;
    }

    // Print total team statistics
    printf("Total Team Statistics:\n");
    printf("Total At Bats: %d, Total Hits: %d, Total Walks: %d, Total Runs: %d\n", total_atbats, total_hits, total_walks, total_runs);

    return 0;
}
