typedef struct Node {
    char data;
    struct Node* next;
} Node;
Node* head = (Node*)malloc(sizeof(Node));
head->data = NULL;
head->next = NULL;
Node* current = head;
while (( input = getchar()) != '\n')
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = input;
    new_node->next = NULL;
    current->next = new_node;
    current = new_node;
}
char* output = (char*)malloc(sizeof(char) * (counter + 1)); // allocate memory for the output string
current = head->next;
int i = 0;
while (current != NULL)
{
    output[i] = current->data;
    current = current->next;
    i++;
}
output[i] = '\0'; // add null terminator to the end of the string
printf("Output string: %s\n", output);
current = head;
while (current != NULL)
{
    Node* temp = current;
    current = current->next;
    free(temp);
}
free(output);
