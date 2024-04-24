struct level
{
    // Other members of the struct
    char *level_data;
};

void create_level(struct level *lvl)
{
    lvl->level_data = malloc(get_terminal_size() * sizeof(char));
    if (lvl->level_data == NULL)
    {
        // Error handling if malloc fails
        exit(1);
    }
}

void destroy_level(struct level *lvl)
{
    free(lvl->level_data);
}
int main()
{
    struct level my_level;
    create_level(&my_level);

    // Use my_level.level_data as needed

    destroy_level(&my_level);

    return 0;
}
