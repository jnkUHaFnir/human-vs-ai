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
    int i, atbat, hits, walks, runs;
    struct profile stat[18] = {0};
    
    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team!\n");
        exit(1);
    }

    while (fscanf(flx, "%d %s %s %d %d %d %d", &i, stat[i].name, stat[i].lname, &atbat, &hits, &walks, &runs) != EOF) {
        stat[i].pl_num = i;
        stat[i].atbat += atbat;
        stat[i].hits += hits;
        stat[i].walks += walks;
        stat[i].runs += runs;
        stat[i].batavg = (float)stat[i].hits / stat[i].atbat;
    }

    for (int idx = 0; idx < 18; idx++) {
        if (stat[idx].pl_num != 0) {
            printf("Player %d - %s %s\n", stat[idx].pl_num, stat[idx].name, stat[idx].lname);
            printf("At Bats: %d, Hits: %d, Walks: %d, Runs: %d, Batting Average: %.3f\n\n",
                stat[idx].atbat, stat[idx].hits, stat[idx].walks, stat[idx].runs, stat[idx].batavg);
        }
    }

    // Calculate team's combined statistics
    int total_atbat = 0, total_hits = 0, total_walks = 0, total_runs = 0;
    for (int idx = 0; idx < 18; idx++) {
        total_atbat += stat[idx].atbat;
        total_hits += stat[idx].hits;
        total_walks += stat[idx].walks;
        total_runs += stat[idx].runs;
    }
    
    printf("Team Combined Statistics:\n");
    printf("Total At Bats: %d, Total Hits: %d, Total Walks: %d, Total Runs: %d\n",
        total_atbat, total_hits, total_walks, total_runs);

    fclose(flx);

    return 0;
}
