void service_data_func(char text[]) {
    int menunum = 0; // Index for the main service array
    int menunum_charge = 0; // Index for the charge array
    int value; // Temp storage for the value

    char *pos = strstr(text, "\"service_charge_list\": [");
    if (pos) {
        // Move the pointer to the start of the charge list
        pos = strchr(pos, '{');
        // Loop through the charges
        while (pos) {
            pos = strstr(pos, "\"from\":");
            if (!pos) break;
            pos += strlen("\"from\":");
            value = atoi(pos);
            serv_data[menunum].charge_arr[menunum_charge].from = value;
            ++menunum_charge;
            pos = strchr(pos, '{'); // Move to next charge
        }
    }
}

int main() {
    service_data_func(text);
    printf("From value: %d\n", serv_data[0].charge_arr[0].from);
    return 0;
}
