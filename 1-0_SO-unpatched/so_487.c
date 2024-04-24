        if( rename("duplicate.txt", old_file_name) != 0 ) {
            fprintf( stderr, "Could not rename %s to %s: %s", "duplicate.txt", old_file_name, strerror(errno) );
        }