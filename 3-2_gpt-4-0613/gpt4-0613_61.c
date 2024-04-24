
The 'malloc' makes space for 'rub[idx].name' while 'tmp' already has memory allocated for it (created in 'getString()'). You are trying to assign 'tmp' (a pointer to a string located in HEAP) to 'rub[idx].name' (it has already other memory location assigned with malloc) – effectively 'rub[idx].name' will now point to 'tmp'. This is your source of error.

Use 'strcpy()' instead of simply assigning the pointers while removing the 'malloc' from 'rub[idx].xxx' since 'tmp' already has memory allocated for it:

```C
printf("Nome: ");
tmp = getString();
rub[idx].name = tmp;
