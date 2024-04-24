    jmp_buf jb;
    void *myfunc(void) {
        struct {
            // put all of your local variables here.
            int i;
        } *_;
        void *new_data, *data = malloc(sizeof(*_));
        if (!(new_data = (void *)(intptr_t)setjmp(jb)))
            return data;
        data = new_data;
        /* put your code here */
        free(data);
        return NULL;
    }