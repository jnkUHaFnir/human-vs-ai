#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct service_charge {
    int from;
    int to;
    int charge;
    int slap;
    char percentage[5];
};

struct service {
    int id;
    int provider_id;
    char name[30];
    int price_type;
    int min_value;
    int max_value;
    int sort_order;
    char inquiry_required[5];
    struct service_charge charge_arr[10];
};

struct service serv_data[8]; // Pre-allocated buffer for service data
char text[1000]; // JSON-like text to be parsed

// Helper function to extract integer from text between start and end
int extract_int(const char* text, int start, int end) {
    char buffer[20];
    strncpy(buffer, text + start, end - start);
    buffer[end - start] = '\0'; // Ensure null-termination
    return atoi(buffer);
}

// Main parsing function
void service_data_func(const char* text) {
    // Variable initialization
    int len = strlen(text);
    int serv_idx = 0; // Index for service
    int charge_idx = 0; // Index for service charge
    int i = 0; // Index for text parsing

    // Main parsing loop
    while (i < len) {
        // Parsing logic here...
        // Example: checking for a known field, such as "id"
        if (strncmp(&text[i], "\"id\":", 5) == 0) {
            i += 5; // Move past the "id" field
            while (isspace((unsigned char)text[i])) ++i; // Skip whitespace

            // Parse the integer value of "id"
            int start = i;
            while (isdigit((unsigned char)text[i])) ++i;
            serv_data[serv_idx].id = extract_int(text, start, i);

            // Proceed with parsing other fields in a similar manner...
        }

        // Increment parsing index
        i++;
    }
}

int main() {
    // Populate 'text' with JSON-like data
    // IMPORTANT: This is just a placeholder, as the actual text content is too long
    strcpy(text, "{\"id\": 4806, ...}"); // Simplified data (add your actual JSON-like data here)

    // Parse the JSON-like data
    service_data_func(text);

    // Print parsed data for validation
    printf("ID: %d\n", serv_data[0].id);
    // Print other fields in a similar manner...

    return 0;
}
