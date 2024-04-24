#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int x; // position
    int y; // position
    int z; // position
    int total_node_nums;  // total node numbers
};

struct Element {
    int total_elmt_num; // total element numbers
    struct Node *node; // array of nodes
};

void arr_creator(char *fname, char *str_start, char *str_end) {
    FILE *fl_read;
    char buffer[512], line_buff[20];
    int num_node, tag, line = 0;

    fl_read = fopen(fname, "r");
    if (fl_read == NULL) {
        printf("\n[error reading file] :: in function arr_creator\n");
        return;
    }

    // Scan file for str_start
    while (fgets(buffer, sizeof(buffer), fl_read) != NULL) {
        if (strstr(buffer, str_start)) {
            printf("\nline: %d   string: %s \n", line + 1, str_start);

            fgets(buffer, sizeof(buffer), fl_read);
            num_node = atoi(buffer);
            printf("num_node = %d\n", num_node);

            struct Node *node = malloc(num_node * sizeof(struct Node));
            if (node == NULL) {
                printf("Memory allocation error.\n");
                break;
            }

            for (int i = 0; i < num_node; i++) {
                fgets(buffer, sizeof(buffer), fl_read);
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
}

int main() {
    arr_creator("data.txt", "$Node", "$EndNodes"); // Example usage
    return 0;
}
