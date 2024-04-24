#define LENGTH 45
char* string = NULL;
word_size++;
// free(new_node);
int hash_func(char* hash_val){
    int h = 0;
    int len = strlen(hash_val);
    if(len > 0){
        for (int i = 0; i < len; i++){
            h = (h << 2) ^ hash_val[i];
        }
    }
    return h % HASH_SIZE;
}
if(fscanf(dic, "%ms", &string) != 1){
        if(feof(dic)){
            break;
        } else {
            fprintf(stderr, "Error reading from file (%s)\n", strerror(errno));
            return false;
        }
    }
