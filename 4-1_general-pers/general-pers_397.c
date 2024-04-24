// Define the maximum number of files in a directory
#define MAX_FILES 256

// Change the content type in the file struct to char* instead of char**
typedef struct {
    char* content; // Address of the text in the file
    char* name;    // Filename
    size_t size;   // Included from stddef.h - set by the function
} file;

// Ensure that the directory structure includes the maximum number of files
typedef struct {
    file* files[MAX_FILES];  // The files in the directory
    char* name;              // The directory name
    size_t index;            // The index of the next file - basically the length of the files array - starts at 0
} dir;

// Create a new file and return it
file new_file(char* name, char* content) {
    file new_file;
    new_file.name = name;
    new_file.content = content;
    new_file.size = strlen(content); // Calculate the size of the content

    return new_file;
}

// Add a new file to the directory
void add_file(dir* folder, file new_file) {
    if (folder->index < MAX_FILES) { // Check if there is space in the directory
        folder->files[folder->index] = &new_file; // Store the file pointer in the directory
        folder->index++;
    } else {
        // Handle error: directory is full
        // Display a message or take necessary actions
    }
}

// Find and return a file in the directory by name
file* find_file(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        if (strcmp(folder->files[i]->name, name) == 0) {
            return folder->files[i]; // Return the file if found
        }
    }
    return NULL; // Return NULL if file not found
}

// Read the content of a file in the directory by name
char* read(dir* folder, char* name) {
    file* file_to_read = find_file(folder, name);
    if (file_to_read != NULL) {
        return file_to_read->content; // Return the content of the file
    } else {
        // Handle error: file not found
        // Display a message or take necessary actions
        return NULL;
    }
}

// Create a new file in the directory
void new(dir* folder, char* name, char* content) {
    file new_file = new_file(name, content); // Create a new file
    add_file(folder, new_file); // Add the new file to the directory
}
