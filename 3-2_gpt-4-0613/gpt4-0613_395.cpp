void deleteNode(struct Node *node)
{
    struct Node *next_node = node->next;
    node->data = next_node->data;
    node->next = next_node->next;
    free(next_node);
}
