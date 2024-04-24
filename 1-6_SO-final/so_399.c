    MyNodeStruct *pNewNode = malloc(sizeof(myNodeStruct) + 15000);
    if (pNewNode)
        pNewNode->pMegaBuffer = ((unsigned char *)pNewNode) + sizeof(myNodeStruct);
    