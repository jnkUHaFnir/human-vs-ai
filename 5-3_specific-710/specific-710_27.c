while(fscanf(dic, "%ms", string) != EOF){
    node* new_node = malloc(sizeof(node));
    if(new_node == NULL){
        return false;
    }
    strcpy(new_node->word, string);
    new_node->next = NULL;
    int hash_indx = hash_func(new_node->word);
    node* first = global_hash[hash_indx];
    if(first == NULL){
        global_hash[hash_indx] = new_node;
    } else {
        new_node->next = global_hash[hash_indx];
        global_hash[hash_indx] = new_node;
    }
    word_size++;
}
free(string); // Free the memory allocated for the string read by fscanf
