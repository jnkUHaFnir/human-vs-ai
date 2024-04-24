#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct profile stat[19] = {0}; // Initialize an array of structures for 19 players, assuming player numbers range from 0-18

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team!\n");
        exit(1);
    }

    while (!feof(flx)) {
        int pl_num, atbat, hits, walks, runs;
        fscanf(flx, "%d %s %s %d %d %d %d", &pl_num, stat[pl_num].name, stat[pl_num].lname, &atbat, &hits, &walks, &runs);
        stat[pl_num].pl_num = pl_num;
        stat[pl_num].atbat += atbat;
        stat[pl_num].hits += hits;
        stat[pl_num].walks += walks;
        stat[pl_num].runs += runs;
    }

    // Calculate batting average for each player
    for (int i = 0; i < 19; i++) {
        if (stat[i].atbat > 0) {
            stat[i].batavg = (float)stat[i].hits / stat[i].atbat;
        }
    }

    // Print cumulative data for each player
    for (int i = 0; i < 19; i++) {
        if (stat[i].atbat > 0) {
            printf("Player %d: %s %s | Hits: %d, Walks: %d, RBIs: %d, Batting Average: %.3f\n", stat[i].pl_num, stat[i].name, stat[i].lname, stat[i].hits, stat[i].walks, stat[i].runs, stat[i].batavg);
        }
    }

    // Show combined statistics for the entire team
    int total_hits = 0, total_walks = 0, total_runs = 0;
    float total_batavg = 0;
    
    for (int i = 0; i < 19; i++) {
        total_hits += stat[i].hits;
        total_walks += stat[i].walks;
        total_runs += stat[i].runs;
        total_batavg += stat[i].batavg;
    }

    total_batavg /= 19; // Calculate average batting average for the team

    printf("\nCombined Team Statistics:\n");
    printf("Total Hits: %d, Total Walks: %d, Total RBIs: %d, Average Batting Average: %.3f\n", total_hits, total_walks, total_runs, total_batavg);

    fclose(flx);
    return 0;
}
