    float * foo = NULL;
    void update()
    {
        ...
        foo = (float *)malloc( a * 2 * sizeof(float));
        ...
        float * bar = (float *)realloc( foo, a * 2 * sizeof(float));
        if(bar)
           foo = bar;
        ...
        if(foo != NULL)
        {
            free(foo);
        }
    }