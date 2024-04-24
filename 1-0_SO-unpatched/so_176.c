    uint8_t bytes[6];
    int values[6];
    int i;
    if( 6 == sscanf( mac, "%x:%x:%x:%x:%x:%x%c",
        &values[0], &values[1], &values[2],
        &values[3], &values[4], &values[5] ) )
    {
        /* convert to uint8_t */
        for( i = 0; i < 6; ++i )
            bytes[i] = (uint8_t) values[i];
    }
    else
    {
        /* invalid mac */
    }