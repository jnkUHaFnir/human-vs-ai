int occurrences_of_d = 0;
int occurrences_of_s = 0;
bool last_char_was_percent = false;
char first_format = 0;
char second_format = 0;

for each character c in cfg->pathfmt:
  if c == '%':
      last_char_was_percent = true;
  else:
      if last_char_was_percent:
        if c == 'd':
            occurrences_of_d++;
            if first_format == 0:
              first_format = 'd';
            else if second_format == 0 and first_format != 'd':
              second_format = 'd';
        else if c == 's':
            occurrences_of_s++;
            if first_format == 0:
              first_format = 's';
            else if second_format == 0 and first_format != 's':
              second_format = 's';
        else:
            return false; // invalid format
      last_char_was_percent = false;
if occurrences_of_d == 0 and occurrences_of_s == 0:
  snprintf(j->outpath, sizeof(j->outpath), cfg->pathfmt);
else if occurrences_of_d == 1 and occurrences_of_s == 0:
  snprintf(j->outpath, sizeof(j->outpath), cfg->pathfmt, jobid);
else if occurrences_of_d == 0 and occurrences_of_s == 1:
  snprintf(j->outpath, sizeof(j->outpath), cfg->pathfmt, jobname);
else if occurrences_of_d == 1 and occurrences_of_s == 1:
  if first_format == 'd' and second_format == 's':
      snprintf(j->outpath, sizeof(j->outpath), cfg->pathfmt, jobid, jobname);
  else:
      snprintf(j->outpath, sizeof(j->outpath), cfg->pathfmt, jobname, jobid);
else:
  return false; // invalid format