std::string str;
char buffer[512];

// format the string with sprintf
int len = snprintf(buffer, sizeof(buffer), "The quick brown %s jumps over the lazy %s", "fox", "dog");
if (len >= sizeof(buffer)) {
    // handle error (string truncated)
}

// copy the formatted string into the std::string
str = buffer;

// send the string to the file stream
std::ofstream outfile("output.txt");
outfile << str;
outfile.close();
