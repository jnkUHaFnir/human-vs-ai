char full_old_file_name[256];
char full_new_file_name[256];

// ... (other parts of the code)

strcpy(full_old_file_name, "full/path/to/directory/"); // Replace with the actual path
strcat(full_old_file_name, old_file_name);
fp = fopen(full_old_file_name, "rt");

// ... (other parts of the code)

rename("full/path/to/directory/duplicate.txt", full_old_file_name);
remove("full/path/to/directory/duplicate.txt");
