int processFile(const char *filename, 
                YAML::Emitter &out_yaml, 
                char *ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    if (ground_truth_filename == nullptr)
    {
        const int max_filename_length = 256; // Define a maximum length for the filename
        char default_ground_truth_filename[max_filename_length];
        snprintf(default_ground_truth_filename, max_filename_length, "%s.yaml", filename);
        ground_truth_filename = new char[max_filename_length]; // Allocate memory for the default filename
        strcpy(ground_truth_filename, default_ground_truth_filename);
    }

    std::ifstream imgstrm(filename, std::ios::binary | std::ios::in);

    if (imgstrm.fail() || !imgstrm.is_open())
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return FILE_ERROR;
    }

    // get ground truth
    std::ifstream ground_truth_stream(ground_truth_filename);

    if (!ground_truth_stream.is_open()) 
    {
        fprintf(stderr, "Failed to open file: %s\n", ground_truth_filename);
        return FILE_ERROR;
    }
    
    // Don't forget to release the memory allocated for ground_truth_filename
    delete[] ground_truth_filename;

    return 0;
}

// How the function is called:
char *ground_truth_filename = nullptr;
for (int i = 1; i + 1 < argc; i += 2) {
    if (!strcmp(argv[i], "--snapshot-markup")) {
        ground_truth_filename = argv[i + 1];
        markupFlag = true;
    }
}
processFile(filename, out_yaml, ground_truth_filename);
