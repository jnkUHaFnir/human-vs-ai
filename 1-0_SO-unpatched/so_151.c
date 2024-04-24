    int main(){
        FILE *ifp;
        char newword[20];
        node * head = NULL;
        node  *last = NULL;
        node  *current;
    
        ifp = fopen("para.txt","r");
    
        while(fscanf(ifp,"%s",newword) != EOF){
             current = malloc(sizeof(node));
             strcpy(current -> word,newword);
             if(last) {
                 last->next = current;
             }
             else {
                 head = current;
             }
             last = current;
        }
    
        return 0;
    }