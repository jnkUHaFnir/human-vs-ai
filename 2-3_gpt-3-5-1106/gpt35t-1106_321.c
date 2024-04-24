// ... (inside listFilesRecursively function)
while ((dp = readdir(dir)) != NULL) {
    // ... (other code remains the same)
}

// Sort the files array
sortFilesArray(files, counter);

// Output the sorted array
for (int i = 0; i < counter; i++) {
    printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
}
