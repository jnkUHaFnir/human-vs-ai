while (1) {
    int i = 0;
    int Wstart = 0;
    int Wend = 0;
    int menunum = 0;
    int len = strlen(text);
    int menunum_charge = 0;

    // ...
}
if (text[i] == '"' && text[i+1] == 'i' && text[i+2] == 'd') {
    i += 4; // Skip "id":
    while (1) {
        // ...
    }
}
if (text[i] == 's' && text[i+1] == 'e' && ... && text[i+18] == 't') {
    i += 19; // Skip "service_charge_list":
    while (1) {
        // ...
    }
}
if (text[i] == 'f' && ... && text[i+3] == 'm') {
    i += 5; // Skip "from":
    while (1) {
        // ...
        i++;
        break;
    }
}
serv_data[menunum].charge_arr[menunum_charge].from = atoi(name);
menunum_charge++;
