char text[1000]="{\"success\": true,\"language\": \"en\",\"action\": \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": 10000,\"sort_order\": 2,\"inquiry_required\": true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": 1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": 54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1},{\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": 5,\"percentage\": true2}]";
if(text[i] == '"' && text[i+1] == 'i'&& text[i+2] == 'd') {
    while (1) { //while "id
        if(text[i] == ':') {
            // ...
        } else if(text[i] == ',' || text[i] == '}' ) {
            // ...
            menunum++; // add this line
            memset(name, 0, sizeof(name));
            i++;
            break;
        } else {
            i=i+1;
        }
    }//while id
} else if(text[i] == 's' && text[i+1] == 'e'&& text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&& text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8] == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] == 'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&& text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&& text[i+18] == 't') {
    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }
        if(text[i] == 'f' && text[i+1] == 'r'&& text[i+2] == 'o'&& text[i+3] == 'm') {
            while (1) { //while from
                if(text[i] == ':') {
                    // ...
                } else if(text[i] == ',' || text[i] == '}' ) {
                    // ...
                    menunum_charge++; // add this line
                    memset(name, 0, sizeof(name));
                    i++;
                    break;
                } else {
                    i=i+1;
                }
            }
        } else {
            i++;
        }
    }
}
