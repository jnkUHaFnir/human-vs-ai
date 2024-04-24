    void insert( node **head, int x){
    	
    	node **temp = head;
    	while( *temp != NULL ){
    		temp = &((*temp)->next);
    	}
    	*temp = malloc( sizeof(node) );
    	(*temp)->next=NULL;
    	(*temp)->data=x;
    }