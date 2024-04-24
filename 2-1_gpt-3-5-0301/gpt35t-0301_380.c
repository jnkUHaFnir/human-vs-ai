char text[1000]="{\"success\": true,\"language\": \"en\",\"action\": \
                \"GetServiceList\",\"version\": 1,\"data\": {\"service_list\": \
                [{\"id\": 4806,\"provider_id\": 581,\"name\": \"Bill Payment (MG SC AC)\",\"price_type\": 0,\"min_value\": 30,\"max_value\": \
                10000,\"sort_order\": 2,\"inquiry_required\": \
                true,\"service_charge_list\": [{\"from\": 1,\"to\": 547,\"charge\": \
                1,\"slap\": 1,\"percentage\": true1},{\"from\": 2,\"to\": \
                54875,\"charge\": 4,\"slap\": 5,\"percentage\": true1}, \
                {\"from\": 2,\"to\": 68945,\"charge\": 4,\"slap\": \
                5,\"percentage\": true2}]}}}";
while (1) {
    if (i >= len) {
        break;
    }
    if (text[i] == '"' && text[i+1] == 'i' && text[i+2] == 'd') {
        while (1) {
            if (text[i] == ':') {
                Wstart = i+1;
                Wend = 0;
                i++;
            } else if (text[i] == ',' || text[i] == '}') {
                Wend = i;

                strncpy(name, text+Wstart, Wend-Wstart);
                serv_data[menunum].id = atoi(name);
                memset(name, 0, sizeof(name));
                i++;
                break;
            } else {
                i++;
            }
        }
    } else if (text[i] == 'p' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'v' && text[i+4] == 'i' && text[i+5] == 'd' && text[i+6] == 'e' && text[i+7] == 'r' && text[i+8] == '_' && text[i+9] == 'i' && text[i+10] == 'd') {
        while (1) {
            if (text[i] == ':') {
                Wstart = i+1;
                Wend = 0;
                i++;
            } else if (text[i] == ',' || text[i] == '}') {
                Wend = i;

                strncpy(name, text+Wstart, Wend-Wstart);
                serv_data[menunum].provider_id = atoi(name);
                memset(name, 0, sizeof(name));
                i++;
                break;
            } else {
                i++;
            }
        }
    } else if (text[i] == 'n' && text[i+1] == 'a' && text[i+2] == 'm' && text[i+3] == 'e') {
        while (1) {
            if (text[i] == ':') {
                Wstart = i+2;
                Wend = 0;
                i++;
            } else if (text[i] == '"' && text[i-1] != '\\') {
                Wend = i-1;

                strncpy(serv_data[menunum].name, text+Wstart, Wend-Wstart+1);
                i++;
                break;
            } else {
                i++;
            }
        }
    } else if (text[i] == 's' && text[i+1] == 'e' && text[i+2] == 'r' && text[i+3] == 'v' && text[i+4] == 'i' && text[i+5] == 'c' && text[i+6] == 'e' && text[i+7] == '_' && text[i+8] == 'c' && text[i+9] == 'h' && text[i+10] == 'a' && text[i+11] == 'r' && text[i+12] == 'g' && text[i+13] == 'e' && text[i+14] == '_' && text[i+15] == 'l' && text[i+16] == 'i' && text[i+17] == 's' && text[i+18] == 't') {
        while (1) {
            if (i >= len) {
                break;
            }
            if (text[i] == '{') {
                menunum_charge++;
                i++;
            } else if (text[i] == 'f' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'm') {
                while (1) {
                    if (text[i] == ':') {
                        Wstart = i+1;
                        Wend = 0;
                        i++;
                    } else if (text[i] == ',' || text[i] == '}') {
                        Wend = i;

                        strncpy(name, text+Wstart, Wend-Wstart);
                        serv_data[menunum].charge_arr[menunum_charge-1].from = atoi(name);
                        memset(name, 0, sizeof(name));
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (text[i] == 't' && text[i+1] == 'o') {
                while (1) {
                    if (text[i] == ':') {
                        Wstart = i+1;
                        Wend = 0;
                        i++;
                    } else if (text[i] == ',' || text[i] == '}') {
                        Wend = i;

                        strncpy(name, text+Wstart, Wend-Wstart);
                        serv_data[menunum].charge_arr[menunum_charge-1].to = atoi(name);
                        memset(name, 0, sizeof(name));
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (text[i] == 'c' && text[i+1] == 'h' && text[i+2] == 'a' && text[i+3] == 'r' && text[i+4] == 'g' && text[i+5] == 'e') {
                while (1) {
                    if (text[i] == ':') {
                        Wstart = i+1;
                        Wend = 0;
                        i++;
                    } else if (text[i] == ',' || text[i] == '}') {
                        Wend = i;

                        strncpy(name, text+Wstart, Wend-Wstart);
                        serv_data[menunum].charge_arr[menunum_charge-1].charge = atoi(name);
                        memset(name, 0, sizeof(name));
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (text[i] == 's' && text[i+1] == 'l' && text[i+2] == 'a' && text[i+3] == 'p') {
                while (1) {
                    if (text[i] == ':') {
                        Wstart = i+1;
                        Wend = 0;
                        i++;
                    } else if (text[i] == ',' || text[i] == '}') {
                        Wend = i;

                        strncpy(name, text+Wstart, Wend-Wstart);
                        serv_data[menunum].charge_arr[menunum_charge-1].slap = atoi(name);
                        memset(name, 0, sizeof(name));
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (text[i] == 'p' && text[i+1] == 'e' && text[i+2] == 'r' && text[i+3] == 'c' && text[i+4] == 'e' && text[i+5] == 'n' && text[i+6] == 't' && text[i+7] == 'a' && text[i+8] == 'g' && text[i+9] == 'e') {
                while (1) {
                    if (text[i] == ':') {
                        Wstart = i+1;
                        Wend = 0;
                        i++;
                    } else if (text[i] == ',' || text[i] == '}') {
                        Wend = i-1;

                        strncpy(name1, text+Wstart, Wend-Wstart+1);
                        memset(name1, 0, sizeof(name1));
                        serv_data[menunum].charge_arr[menunum_charge-1].percentage[(sizeof(serv_data[menunum].charge_arr[menunum_charge-1].percentage)/sizeof(serv_data[menunum].charge_arr[menunum_charge-1].percentage[0]))-1]='\0';
                        strncpy(serv_data[menunum].charge_arr[menunum_charge-1].percentage, text+Wstart, Wend-Wstart+1);
                        memset(name, 0, sizeof(name));
                        i++;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (text[i] == '}') {
                i++;
                break;
            } else {
                i++;
            }
        }
    } else {
        i++;
    }
}
