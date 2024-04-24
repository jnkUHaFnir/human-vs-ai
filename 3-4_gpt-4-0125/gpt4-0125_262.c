struct futbaler
{
    char ime[15];
    char prezime[20];
    char pozicija[15];
    char godiste[5]; // Adjusted to hold 4 characters + null terminator
};
scanf("%14s", (pok+i)->ime);       // Max 14 characters for ime
scanf("%19s", (pok+i)->prezime);   // Max 19 characters for prezime
scanf("%14s", (pok+i)->pozicija);  // Max 14 characters for pozicija
scanf("%4s",  (pok+i)->godiste);   // Max 4 characters for godiste
