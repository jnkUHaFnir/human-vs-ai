#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LGT 30

struct profile {
    int pl_num;
    char name[LGT];
    char lname[LGT];
    int atbat_total;
    int hits_total;
    int walks_total;
    int runs_total;
    float batavg;
};

int main(void)
{
    FILE *flx;
    struct profile stat[19] = {0};

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team.txt!\n");
        exit(1);
    }

    while (1) {
        int num;
        char fname[LGT], lname[LGT];
        int atbat, hits, walks, runs;

        if (fscanf(flx, "%d %s %s %d %d %d %d", &num, fname, lname, &atbat, &hits, &walks, &runs) != 7) {
            break; // Exit loop on reaching end of file
        }

        // Update cumulative totals for the player
        stat[num].pl_num = num;
        strcpy(stat[num].name, fname);
        strcpy(stat[num].lname, lname);
        stat[num].atbat_total += atbat;
        stat[num].hits_total += hits;
        stat[num].walks_total += walks;
        stat[num].runs_total += runs;
    }

    // Calculate batting average for each player
    for (int i = 0; i < 19; i++) {
        if (stat[i].atbat_total > 0) {
            stat[i].batavg = (float)stat[i].hits_total / stat[i].atbat_total;
        }
    }

    // Display cumulative data for each player
    for (int i = 0; i < 19; i++) {
        if (stat[i].pl_num != 0) {
            printf("Player %d %s %s - Total At Bats: %d Hits: %d Walks: %d Runs: %d Batting Avg: %.2f\n",
                   stat[i].pl_num, stat[i].name, stat[i].lname, stat[i].atbat_total,
                   stat[i].hits_total, stat[i].walks_total, stat[i].runs_total, stat[i].batavg);
        }
    }

    fclose(flx);
    return 0;
}
