tmp = getString();
rub[idx].name = (char *) malloc(strlen(tmp));
rub[idx].name = tmp;
// Similarly for surname, address, and number
tmp = getString();
rub[idx].name = (char *) malloc(strlen(tmp) + 1); // allocate enough memory for the string and null terminator
strcpy(rub[idx].name, tmp); // copy the content of tmp into rub[idx].name
// Similarly for surname, address, and number
ttmp[i].name = rub[k].name;
ttmp[i].surname = rub[k].surname;
ttmp[i].address = rub[k].address;
ttmp[i].number = rub[k].number;
ttmp[i].name = (char *) malloc(strlen(rub[k].name) + 1);
strcpy(ttmp[i].name, rub[k].name);
// Similarly for surname, address, and number
