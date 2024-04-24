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
    int i, jc, flow = 0;
    struct profile stat[18] = {{0}};

    if ((flx = fopen("team.txt", "r")) == NULL) {
        fprintf(stderr, "Can't read file team!\n");
        exit(1);      
    }

    while (fscanf(flx, "%d %s %s %d %d %d %d", &i, stat[i].name, stat[i].lname, &stat[i].atbat, &stat[i].hits, &stat[i].walks, &stat[i].runs) == 7) {
        stat[i].pl_num = i;
        stat[i].batavg = (float)stat[i].hits / stat[i].atbat;
    }

    fclose(flx);

    printf("Player Stats:\n");
    printf("Player | Name | At Bats | Hits | Walks | Runs | Batting Average\n");
    for(int k = 0; k < 18; k++) {
        if(stat[k].pl_num != 0) {
            printf("%d %s %s %d %d %d %d %.3f\n", stat[k].pl_num, stat[k].name, stat[k].lname, stat[k].atbat, stat[k].hits, stat[k].walks, stat[k].runs, stat[k].batavg);
        }
    }

    // Calculate and display team totals
    int total_atbats = 0, total_hits = 0, total_walks = 0, total_runs = 0;
    for(int l = 0; l < 18; l++) {
        if(stat[l].pl_num != 0) {
            total_atbats += stat[l].atbat;
            total_hits += stat[l].hits;
            total_walks += stat[l].walks;
            total_runs += stat[l].runs;
        }
    }

    printf("\nTeam Totals:\n");
    printf("Total At Bats: %d\n", total_atbats);
    printf("Total Hits: %d\n", total_hits);
    printf("Total Walks: %d\n", total_walks);
    printf("Total Runs: %d\n", total_runs);

    return 0;
}
