    Array2<T> & addData(T dataToAdd)
    {
        this->data = realloc(this->data, this->size + 1);
        this->data[this->size] = dataToAdd;
        this->size++;
        return *this;
    };