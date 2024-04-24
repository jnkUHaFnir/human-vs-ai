        while (fscanf (filein_ptr, " %[^,], %lf\n", teamname, &teamscore[n]) == 2) {
            fprintf (fileout_ptr, "%s    %f\n", teamname, teamscore[n++]);
        }