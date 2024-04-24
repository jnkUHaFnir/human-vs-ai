    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    struct Node {
        int tag;
        int x; //position
        int y; //position
        int z; //position
    };
    
    struct Nodes {
        int total_node_num;
        struct Node *nodes;//array of node
    };
    
    struct Nodes *arr_creator(char *fname, char *str_start, char *str_end){ 
        FILE *fl_read; 
        char buffer[512]; 
        int line = 0; 
    
        fl_read = fopen(fname, "r"); 
        if(fl_read == NULL){
            printf("\n[error reading file] :: in function arr_creator\n");
            return NULL; 
        }
    
        while(fgets(buffer, sizeof(buffer),fl_read) != NULL ) {
            ++line;
            if(strstr(buffer, str_start)){
                int i, num_node;//work
                struct Node *node;//work
                
                printf("\nline: %d   string: %s \n", line, str_start); 
                struct Nodes *nodes = malloc(sizeof(struct Nodes));
                num_node = nodes->total_node_num = atoi(fgets(buffer,sizeof(buffer),fl_read));
                printf("num_node = %d\n", num_node); 
                node = nodes->nodes = malloc((num_node)*sizeof(struct Node)); 
                for(i=0;;i++){
                    fgets(buffer,sizeof(buffer),fl_read);
                    if(strstr(buffer, str_end)){
                        if(i == num_node){
                            printf("buffer at break :: %s", buffer); 
                        } else if(i < num_node){
                            nodes->total_node_num = i;
                            fprintf(stderr, "The number of nodes less than the specified!");
                        } else if(i > num_node){
                            fprintf(stderr, "The number of nodes more than the specified!\n"
                                            "*read only the number of specified.*");
                        }
                        fclose(fl_read);
                        return nodes;
                    }
                    //read node check print
                    sscanf(buffer," %d %d %d %d ", &node[i].tag, &node[i].x, &node[i].y, &node[i].z);
                    printf("--------------\n"); 
                    printf("   Node %d   \n", node[i].tag); 
                    printf("--------------\n"); 
                    printf("node[%d].x = %d\n",i, node[i].x); 
                    printf("node[%d].y = %d\n",i, node[i].y); 
                    printf("node[%d].z = %d\n",i, node[i].z); 
                    printf("BUFFER  ::  %s", buffer); 
                }
            }
        }
        fclose(fl_read);
        return NULL;
    }
    
    int main(void) {
        struct Nodes *nodes;
        struct Node  *node;
        int i;
        nodes=arr_creator("data.txt", "$Node", "$EndNodes");
        node = nodes->nodes;
        for(i=0;i<nodes->total_node_num;++i){
            printf("\n   Node %d   \n", node[i].tag); 
            printf("--------------\n"); 
            printf("node[%d].x = %d\n",i, node[i].x); 
            printf("node[%d].y = %d\n",i, node[i].y); 
            printf("node[%d].z = %d\n",i, node[i].z); 
        }
        return 0;
    }