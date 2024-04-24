// Assuming godiste has been changed to char godiste[5];
scanf("%14s", (pok+i)->ime);
scanf("%19s", (pok+i)->prezime);
scanf("%14s", (pok+i)->pozicija);
scanf("%4s", (pok+i)->godiste); // Reads a max of 4 characters, leaving room for '\0'
