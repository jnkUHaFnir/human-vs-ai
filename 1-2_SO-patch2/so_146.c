        Tree *create(const char *word) {
            Tree *temp;
            temp = malloc(sizeof(Tree));
            temp->left = temp->right =  NULL;
            temp->val = 1;
            temp->word = strdup(word);
            return temp;
        }