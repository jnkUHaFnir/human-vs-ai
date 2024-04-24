    Array2<T> & addData(T dataToAdd)
    {
        realloc(this->data, this->size + 1);
        this->data[this->size] = dataToAdd;
        this->size++;
        return *this;
    };