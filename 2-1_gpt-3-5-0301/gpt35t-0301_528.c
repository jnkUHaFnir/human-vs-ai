strcpy(path_copy, path);
// ...
strcat(path_copy, "/");
strcat(path_copy, entry->d_name);
closedir(directory);
remove(path);
free(path_copy);
return 0;
