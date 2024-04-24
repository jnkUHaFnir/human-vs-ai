        Tree *insert(Tree *aTree, const char *word) {
            if (aTree == NULL) {
                return create(word);
            switch (alpha(aTree->word, word)) {
                case 0:
                    aTree->left = insert(aTree->left, word);
                    break;
                case 1:
                    aTree->right = insert(aTree->right, word);
                    break;
                case 2:
                    aTree->val++;
                    break;
                }
            }
            return aTree;
        }