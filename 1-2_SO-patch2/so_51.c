    char *buffer;
    int num_read;
    int buffer_size;
    
    buffer_size = 100;
    buffer = malloc(buffer_size);
    num_read = 0;
    while (!finished_reading()) {
        char c = read_next_byte();
        if (num_read >= buffer_size) {
            buffer_size *= 2; // try a buffer that's twice as big as before
            buffer = realloc(buffer, buffer_size);
        }
        buffer[num_read] = c;
        num_read++;
    }