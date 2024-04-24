    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    
    typedef struct element {
        int *array;
        int size;
    } Element;
    
    bool Element_equal(Element *a, Element *b){
        return memcmp(a->array, b->array, a->size * sizeof(*a->array));
    }
    
    Element *E_copy(Element *e){
        Element *el = malloc(sizeof(*el));
        el->array = malloc(e->size * sizeof(*e->array));
        memcpy(el->array, e->array, e->size * sizeof(*e->array));
        el->size  = e->size;
    }
    void E_print(Element *e){
        int i;
        for(i=0; i<e->size; i++)
            printf("%d ", e->array[i]);
        printf("\n");
    }
    
    typedef struct node {
        Element *data;
        int level;
        struct node *next;
    } Node;
    
    void Node_drop(Node *node){
        free(node->data->array);
        free(node->data);
        free(node);
    }
    
    typedef struct queque {
        Node *top;
        Node *tail;
    } Queque;
    
    Queque *Q_new(void){
        return calloc(1, sizeof(Queque));
    }
    
    Node *Q_deq(Queque *q){
        if(q->top){
            Node *node = q->top;
            q->top = q->top->next;
            return node;
        }
        return NULL;
    }
    
    void Q_drop(Queque *q){
        Node *node;
        while(node = Q_deq(q))
            Node_drop(node);
        free(q);
    }
    
    void Q_enq(Queque *q, Element *element, int level){
        Node *node  = malloc(sizeof(*node));
        node->data  = element;
        node->level = level;
        node->next  = NULL;
        q->tail = q->top ? (q->tail->next = node) : (q->top = node);
    }
    
    Element **transpose(Element *e){
        int l = e->size;
        Element **b = malloc(l * sizeof(*b));
        int i, j;
        for (i = 0; i < l; i++) {
            j = (i + 1) % l;
            Element *copy = E_copy(e);
            int t = copy->array[i];
            copy->array[i] = copy->array[j];
            copy->array[j] = t;
            b[i] = copy;
        }
        return b;
    }
    
    int Cyc_Ken_Tau(Element *start, Element *goal){
        Queque *queque = Q_new();
        Q_enq(queque, E_copy(start), 0);//level 0
    
        while(true){
            Node *node = Q_deq(queque);
            if(Element_equal(node->data, goal)==0){
                int ret = node->level;
                Node_drop(node);
                Q_drop(queque);
                return ret;
            }
            Element **new_list = transpose(node->data);
            int i;
            for(i=0; i < node->data->size; ++i){
                Q_enq(queque, new_list[i], node->level + 1);
            }
            free(new_list);
            Node_drop(node);
        }
    }
    
    int main(){
        int a[] = {2, 3, 4, 1};
        int b[] = {1, 2, 4, 3};
        int n = sizeof(a)/sizeof(*a);
        Element start = { a, n };
        Element goal  = { b, n };
        int level = Cyc_Ken_Tau(&start, &goal);
    
        printf("%d\n", level);
        return 0;
    }