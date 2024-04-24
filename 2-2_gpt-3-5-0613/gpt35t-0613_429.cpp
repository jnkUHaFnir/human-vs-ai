int processFile(const char *filename, 
                YAML::Emitter &out_yaml, 
                const char *ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    char default_filename[256];
    if (ground_truth_filename == NULL)
    {
        sprintf(default_filename, "%s.yaml", filename);     
        ground_truth_filename = default_filename;
    }

    std::ifstream imgstrm(filename, std::ios::binary | std::ios::in);

    if (imgstrm.bad() || !imgstrm.is_open())
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
}

// Function call
const char *ground_truth_filename = NULL;
for (int i = 1; i + 1 < argc; i += 2) {
    if (!strcmp(argv[i], "--snapshot-markup")) {
        ground_truth_filename = argv[i + 1];
        markupFlag = true;
    }
}
processFile(filename, out_yaml, ground_truth_filename);
