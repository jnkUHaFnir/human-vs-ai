    char* CommandLine = 0;
    unsigned int CommandLineLength = 0;
    
    for (unsigned int i = 0; i < argc; i++) {
        CommandLineLength += strlen(argv[i]);
    }
    
    CommandLine = new char[CommandLineLength + 1];
    *CommandLine = '\0';
    
    for (unsigned int i = 0; i < argc; i++) {
        int HasSpace = strchr(argv[i], " ") != NULL;
        if (HasSpace) {
            strcat(CommandLine, "\"");
        }
        strcat(CommandLine, argv[i]);
        if (HasSpace) {
            strcat(CommandLine, "\"");
        }
        strcat(CommandLine, " ");
    }
    // Dom something with CommandLine ...
    delete [] CommandLine;