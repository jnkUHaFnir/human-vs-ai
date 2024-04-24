    void insert( node **head, int x){
    	
    	node **ptr_new = head;
    	while( *ptr_new != NULL ){
    		ptr_new = &((*ptr_new)->next);
    	}
        
        // now temp refers either to head or to next of the last node.
    	*ptr_new = malloc( sizeof(node) );
    	(*ptr_new)->next = NULL;
    	(*ptr_new)->data = x;
    }