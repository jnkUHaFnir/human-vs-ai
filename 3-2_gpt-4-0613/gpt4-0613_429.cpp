int processFile(const std::string &filename, YAML::Emitter &out_yaml, std::string &groundTruthFilename)
{   

    if (groundTruthFilename.empty())
        groundTruthFilename = filename + ".yaml";        
        
    // other codes

}

// usage
std::string groundTruthFilename;
// assign to groundTruthFilename if provided
processFile(filename, out_yaml, groundTruthFilename)
