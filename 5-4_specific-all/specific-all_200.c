/* search for key in tree */
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, char key[])
{
    /* traverse the tree inOrder */
    if (treePtr == NULL)
    {
        printf("%p\n", (void *)treePtr);
        return NULL; /* key not found */
    }

    int compareResult = strcmp(key, treePtr->data);
    if (compareResult == 0)
    {
        return treePtr; /* key found */
    }
    else if (compareResult < 0)
    {
        return binaryTreeSearch(treePtr->leftPtr, key); /* search left */
    }
    else
    {
        return binaryTreeSearch(treePtr->rightPtr, key); /* search right */
    }
}
