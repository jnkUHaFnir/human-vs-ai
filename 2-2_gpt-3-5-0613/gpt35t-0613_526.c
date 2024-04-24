person *p = malloc(sizeof(person) + sizeof(char) * array_size);
p->age = 10;
p->sex = 'm';
strcpy(p->name, "John");
