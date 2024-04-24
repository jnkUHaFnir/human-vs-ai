    jmp_buf jb;
    void *myfunc(void) {
        static struct {
            // put all of your local variables here.
            void *new_data, *data;
            int i;
        } *_;
        _ = malloc(sizeof(*_));
        _.data = _;
        if (!(_.new_data = (void *)(intptr_t)setjmp(jb)))
            return _.data;
        _.data = _.new_data;
        /* put your code here */
        free(_);
        return NULL;
    }