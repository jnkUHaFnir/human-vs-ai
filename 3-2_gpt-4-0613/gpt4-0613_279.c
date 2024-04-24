else if(text[i] == 's' && text[i+1] == 'e'&&
              text[i+2] == 'r'&& text[i+3] == 'v'&& text[i+4] == 'i'&&
              text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& text[i+8]
              == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] ==
              'r'&& text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&&
              text[i+15] == 'l'&& text[i+16] == 'i'&& text[i+17] == 's'&&
              text[i+18] == 't') {
    while (1)//while ALL
    {
        if(i>=len) {
            break;
        }
        ...
    }
}
else if(
    text[i] == 's' && text[i+1] == 'e'&& text[i+2] == 'r'&& text[i+3] == 'v'&&
    text[i+4] == 'i'&& text[i+5] == 'c'&& text[i+6] == 'e'&& text[i+7] == '_'&& 
    text[i+8] == 'c'&& text[i+9] == 'h'&& text[i+10] == 'a'&& text[i+11] == 'r'&&
    text[i+12] == 'g'&& text[i+13] == 'e'&& text[i+14] == '_'&& text[i+15] == 'l'&& 
    text[i+16] == 'i'&& text[i+17] == 's'&& text[i+18] == 't'
) {
    i += 19; // Skip "service_charge_list"
    while (1)//while for service_charge_list
    {
        if(i>=len) {
            break;
        }

        // Check for the end of current service_charge_list
        if(text[i] == ']') {
            break;
        }

        if(text[i] == 'f' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'm') {
            while (1) { //while from
                ...
            }
            menunum_charge++; // Count charges in current service_charge_list
        } else {
            i++;
        }
    }
    menunum++; // Count services
}
