void insertNode(TreeNodePtr *treePtr, char value[])
{
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));
        if (*treePtr != NULL)
        {
            strcpy((*treePtr)->data, value);
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
        {
            printf("%s not inserted. No memory available.\n", value);
        }
    }
    else
    {
        if (strcmp(value, (*treePtr)->data) < 0)
        {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        else if (strcmp(value, (*treePtr)->data) > 0)
        {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else
        {
            printf("dup");
        }
    }
}
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[])
{
    if (treePtr == NULL)
    {
        printf("%p\n", (void*)treePtr);
        return NULL;      /* key not found */
    }
    else if (strcmp(treePtr->data, key) == 0)
    {
        return treePtr;       /* key found */
    }
    else if (strcmp(key, treePtr->data) < 0)
    {
        return binaryTreeSearch(treePtr->leftPtr, key);  /* search left subtree */
    }
    else // (strcmp(key, treePtr->data) > 0)
    {
        return binaryTreeSearch(treePtr->rightPtr, key); /* search right subtree */
    }
}
