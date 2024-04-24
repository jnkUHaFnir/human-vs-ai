for (int i = 0; i < MAX_PLANES_IN_A_FLIGHT; i++) {
  for (int j = 0; j < MAX_FLIGHT_ENTRIES; j++) {
    memset(&FlightEntries[i][j], 0, sizeof(FLIGHT_ENTRY_TYPE)); // Initialize to zero
  }
}
FLIGHT_ENTRY_TYPE** FlightEntries = malloc(MAX_PLANES_IN_A_FLIGHT * sizeof(FLIGHT_ENTRY_TYPE*));
for (int i = 0; i < MAX_PLANES_IN_A_FLIGHT; i++) {
  FlightEntries[i] = malloc(MAX_FLIGHT_ENTRIES * sizeof(FLIGHT_ENTRY_TYPE));
}
