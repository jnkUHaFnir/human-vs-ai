        while (fscanf (filein_ptr, " %29[^,],%lf", teamname, &teamscore[n]) == 2) {
            fprintf (fileout_ptr, "%s    %f\n", teamname, teamscore[n++]);
            if (n == MAXS) {  /* check data doesn't exceed MAXS */
                fprintf (stderr, "warning: data exceeds MAXS.\n");
                break;
            }
        }