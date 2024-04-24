struct YourStructName* myStruct = malloc(sizeof(struct YourStructName));
myStruct->size = 10; // Assuming the size is 10
myStruct->array = malloc(myStruct->size * sizeof(int));
