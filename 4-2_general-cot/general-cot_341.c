#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x; // position
    int y; // position
    int z; // position
};

void arr_creator(char *fname, char *str_start, char *str_end);

void arr_creator(char *fname, char *str_start, char *str_end) {

    FILE *fl_read;
    char buffer[512];
    int i, num_node, tag, line = 0;

    fl_read = fopen(fname, "r");
    if(fl_read == NULL) {
        printf("\n[error reading file] :: in function arr_creator\n");
        return;
    }

    // Scan file for str_start
    while(fgets(buffer, sizeof(buffer), fl_read) != NULL) {
        if (strstr(buffer, str_start)) {
            printf("\nline: %d   string: %s \n", line + 1, str_start);

            fgets(buffer, sizeof(buffer), fl_read);

            num_node = atoi(buffer);
            printf("num_node = %d\n", num_node);
            struct Node *node;
            node = malloc((num_node + 1) * sizeof(struct Node));

            for (i = 1; i < num_node + 1; i++) {
                fgets(buffer, sizeof(buffer), fl_read); // Read the next line

                sscanf(buffer, "%d %d %d %d", &tag, &node[i].x, &node[i].y, &node[i].z);

                printf("--------------\n");
                printf("   Node %d   \n", tag);
                printf("--------------\n");
                printf("node[%d].x = %d\n", i, node[i].x);
                printf("node[%d].y = %d\n", i, node[i].y);
                printf("node[%d].z = %d\n", i, node[i].z);
            }
        }
        line++;
        if (strstr(buffer, str_end)) {
            printf("buffer at break :: %s", buffer);
            break;
        }
    }
    
    if (fl_read) {
        fclose(fl_read);
    }
    
    // Don't forget to free the allocated memory
    free(node);
}

int main() {
    arr_creator("your_file_name_here.txt", "$Node", "$EndNodes");

    return 0;
}
