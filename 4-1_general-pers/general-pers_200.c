/* search for key in tree */
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, const char key[])
{
    /* traverse the tree inOrder */
    if (treePtr == NULL)
    {
        printf("%p\n", (void*)treePtr);

        return NULL; /* key not found */
    }
    else if (strcmp(treePtr->data, key) == 0)
    {
        return treePtr; /* key found */
    }
    else if (strcmp(key, treePtr->data) < 0)
    {
        return binaryTreeSearch(treePtr->leftPtr, key); /* search left */
    }
    else // (strcmp(key, treePtr->data) > 0)
    {
        return binaryTreeSearch(treePtr->rightPtr, key); /* search right */
    }
}
