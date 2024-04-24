	#define MAX_NAME_LEN 10-1
	#define MAX_LAST_NAME_LEN 10-1
	void Append(Data *head, char *name, char *lastname) 
	{
		// Check preconditions:
		if (NULL == head)
			return;
		if (NULL == name)
			return;
		if (NULL == lastname)
			return;
		if (MAX_NAME_LEN < strlen(name) || MAX_LAST_NAME_LEN < strlen(lastname))
			return; // too long name or lastname
		// implementation
		Data *_newNode = (Data*)malloc(sizeof(Data));   // can return NULL, not checked
		if (NULL != _newNode)
		{
			std::strcpy(_newNode->name, name);				// can overwrite memory
			std::strcpy(_newNode->lastname, lastname);		// can overwrite memory
			_newNode->next = NULL;						    // + _newNode->next not initialized to NULL <-- MAIN ERROR!
			// Iretator
			Data *prt = head;
			if ((*name != '\0') && (*lastname != '\0'))
			{
				// find the last node in the list:
				//Special Case
				if (*head->name == '\0') 						// alien code, covering up for 
				{
					std::strcpy(head->name, name);              // some flaw in the design or other 
					std::strcpy(head->lastname, lastname);      // functions
				}                                               // the strcpy calls can overwrite memory
				else
				{
					while ((int*)prt->next != NULL)           // (int*) not needed, not good
					{
						prt = prt->next;
					}
					prt->next = _newNode;						// + the prt points to the last entry 
																// and the new node is appended.
																// the original code was assigning newNode to ptr.
				}
			}
		}
	}