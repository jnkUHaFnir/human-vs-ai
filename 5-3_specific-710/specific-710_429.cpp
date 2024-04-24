int processFile(const char *filename, YAML::Emitter &out_yaml, char *ground_truth_filename) {   

    if (ground_truth_filename == nullptr) {
        // If ground_truth_filename is not provided by the user, assume the default
        // You can modify the default filename logic here
        const char* default_ground_truth_filename = "default_ground_truth.yaml";
        sprintf(ground_truth_filename, "%s", default_ground_truth_filename);
        std::cout << "Using default ground truth filename: " << default_ground_truth_filename << std::endl;
    }

    // Rest of your code remains unchanged
    // Make sure to handle other cases for ground_truth_filename as needed

}

int main(int argc, char** argv) {
    char *ground_truth_filename = nullptr; // Initialize to nullptr

    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
            markupFlag = true;
        }
    }

    processFile(filename, out_yaml, ground_truth_filename);
    return 0;
}
