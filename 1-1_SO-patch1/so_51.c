    char *buffer;
    int num_read;
    int buffer_size;
    
    buffer_size = 100;
    buffer = malloc(buffer_size);
    num_read = 0;
    while (!finished_reading()) {
        char c = read_next_byte();
        if (num_read >= buffer_size) {
            char *new_buffer;
            buffer_size *= 2; // try a buffer that's twice as big as before
            new_buffer = realloc(buffer, buffer_size);
            if (new_buffer != buffer) {
                free(buffer);
            }
            buffer = new_buffer;
        }
        buffer[num_read] = c;
        num_read++;
    }