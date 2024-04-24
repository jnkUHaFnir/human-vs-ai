if(fresult != 13) {
    // Handle read error
    printf("Error reading line %d\n", i + 1);
}
printf("Read values: %f %f %f %f %f %f %f %f %f %f %f %f %f\n",
    plocalx, plocaly, plocalz, ppitch, proll, pheading,
    pgearpos, pflappos, pbrakepos, pcanopypos, pafterburnon, pkias, ptime);
