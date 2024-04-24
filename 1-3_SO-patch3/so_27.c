            global_hash[hash_indx] = new_node;  // Here you save new_node
        } else {
            new_node->next = global_hash[hash_indx];
            global_hash[hash_indx] = new_node;  // Here you save new_node
        }
        word_size++;
        free(new_node);  // But here you free the memory