int word_size = 0;
#define HASH_SIZE 65536
#define LENGTH 45

node *global_hash[HASH_SIZE] = {NULL};

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int hash_func(char *hash_val)
{
    int h = 0;
    for (int i = 0, j = strlen(hash_val); i < j; i++)
    {
        h = (h << 2) ^ hash_val[i];
    }
    return h % HASH_SIZE;
}

bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        fprintf(stdout, "Error: File is NULL.");
        return false;
    }
    char *string = malloc((LENGTH + 1) * sizeof(char));
    while (fscanf(dic, "%s", string) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, string);
        new_node->next = NULL;
        int hash_indx = hash_func(new_node->word);
        node *first = global_hash[hash_indx];
        if (first == NULL)
        {
            global_hash[hash_indx] = new_node;
        }
        else
        {
            new_node->next = global_hash[hash_indx];
            global_hash[hash_indx] = new_node;
        }
        word_size++;
    }
    fclose(dic);
    free(string);
    return true;
}
