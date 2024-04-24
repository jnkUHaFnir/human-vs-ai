int processFile(const char *filename,
                YAML::Emitter &out_yaml,
                const char *ground_truth_filename)  // Make this a const pointer
{   
    std::cout << "Here" << std::endl;

    // Create a string to store the new ground truth filename if necessary
    std::string gt_filename;

    // Check if the ground_truth_filename is non-null
    if (!ground_truth_filename) {
        // If it's null, generate a new filename based on the input filename
        gt_filename = std::string(filename) + ".yaml";
        ground_truth_filename = gt_filename.c_str();  // Get the C-string from the generated std::string
    }

    std::ifstream imgstrm(filename, std::ios::binary | std::ios::in);
    if (imgstrm.bad() || !imgstrm.is_open()) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return FILE_ERROR;
    }

    // Get ground truth using the potentially new ground truth filename
    std::ifstream ground_truth_stream(ground_truth_filename);
    if (!ground_truth_stream.is_open()) {
        fprintf(stderr, "Failed to open file: %s\n", ground_truth_filename);
        return FILE_ERROR;
    }

    // Rest of the file processing...
}

int main(int argc, char **argv) {
    // ...
    YAML::Emitter out_yaml;
    const char *ground_truth_filename = NULL;  // Use const char* for safety
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
        }
    }
    processFile(filename, out_yaml, ground_truth_filename);
    // ...
}
