void arr_creator(char *fname, char *str_start, char *str_end) {

    FILE *fl_read;
    char buffer[512];
    int i, num_node, tag;

    fl_read = fopen(fname, "r");
    if(fl_read == NULL){
        printf("\n[error reading file] :: in function arr_creator\n");
        return; 
    }

    while(fgets(buffer, sizeof(buffer), fl_read) != NULL) {
        
        if(strstr(buffer, str_start)) { 
            printf("\nFound string: %s\n", str_start);

            fgets(buffer, sizeof(buffer), fl_read); 
            num_node = atoi(buffer);
            printf("num_node = %d\n", num_node);

            struct Node *node;
            node = malloc((num_node + 1) * sizeof(struct Node)); // Corrected the memory allocation

            for(i = 1; i <= num_node; i++) {
                fgets(buffer, sizeof(buffer), fl_read); // Correctly read each line within the loop
                sscanf(buffer, "%d %d %d %d", &tag, &node[i].x, &node[i].y, &node[i].z);

                printf("--------------\n");
                printf("   Node %d   \n", tag);
                printf("--------------\n");
                printf("node[%d].x = %d\n", i, node[i].x);
                printf("node[%d].y = %d\n", i, node[i].y);
                printf("node[%d].z = %d\n", i, node[i].z);
            }

            free(node); // Remember to free the allocated memory once you're done with it
        }
        
        if(strstr(buffer, str_end)) {
            printf("Found end string: %s", str_end); 
            break;
        }
    }

    if(fl_read) {
        fclose(fl_read);
    }
}
