	typedef struct myStruct myStruct;
	struct myStruct
	{
		int        size;
		char      *name;
		myStruct **array;
	};
	static void allocate_node_child_array(myStruct *p_node, int size)
	{
		p_node->array = malloc((size_t)size * sizeof(myStruct *));
		memset(p_node->array, 0, (size_t)size * sizeof(myStruct *));
		p_node->size = size;
	}
	myStruct *allocate_node(char *name, int size)
	{
		myStruct *p_node = malloc(sizeof(myStruct));
		memset(p_node, 0, sizeof(myStruct));
		p_node->name = name;
		allocate_node_child_array(p_node, size);
		return p_node;
	}
	void expand_node_child_array(myStruct *p_node, int size_to_add)
	{
		if (size_to_add < 1 || p_node == NULL)
			return;
		if (p_node->array == NULL)
			allocate_node_child_array(p_node, size_to_add);
		else
		{
			p_node->array = realloc(p_node->array, (size_t)(p_node->size + size_to_add) * sizeof(myStruct *));
			memset(p_node->array + (size_t)p_node->size * sizeof(myStruct *), 0, (size_t)size_to_add * sizeof(myStruct *));
			p_node->size = p_node->size + size_to_add;
		}
	}
	void free_node(myStruct **pp_node)
	{
		// Free p_node and the array but DO NOT free the children
		if (pp_node == NULL || *pp_node == NULL)
			return;
		if ((*pp_node)->array != NULL)
			free((*pp_node)->array);
		free((*pp_node));
		*pp_node = NULL;
	}
	void free_node_and_children(myStruct **pp_node)
	{
		if (pp_node == NULL || *pp_node == NULL)
			return;
		if ((*pp_node)->array != NULL)
		{
			int iChild;
			for (iChild = 0; iChild < (*pp_node)->size; iChild++)
			{
				free_node_and_children(&((*pp_node)->array[iChild]));
			}
		}
		free_node(pp_node);
	}
	myStruct *get_child_node(myStruct *p_node, int index)
	{
		if (index < 0 || index >= p_node->size)
			return 0;
		return p_node->array[index];
	}
	int set_child_node(myStruct *p_node, int index, myStruct *p_child)
	{
		if (index < 0 || index >= p_node->size)
			return FALSE;
		p_node->array[index] = p_child;
		return TRUE;
	}