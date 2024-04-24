    char* CommandLine = 0;
    unsigned int CommandLineSize = 0;
    
    for (unsigned int i = 0; i < argc; i++) {
        CommandLineLength += strlen(argv[i]);
    }
    
    CommandLine = new char[CommandLineLength + 1];
    *CommandLine = '\0';
    
    for (unsigned int i = 0; i < argc; i++) {
        strcat(CommandLine, argv[i]);
        strcat(CommandLine, " ");
    }
    // Dom something with CommandLine ...
    delete [] CommandLine;