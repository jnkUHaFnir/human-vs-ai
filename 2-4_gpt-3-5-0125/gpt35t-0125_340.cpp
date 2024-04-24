Array2<T> *addData(T dataToAdd){
    Array2<T> *tmp = (Array2<T> *)malloc(sizeof(Array2<T>));
    tmp->data = (T *)malloc(sizeof(T)*this->size);
    memcpy(tmp->data, this->getData(), sizeof(T)*this->size);

    Array2<T> *newData = (Array2<T> *)malloc(sizeof(Array2<T>));
    newData->data = (T *)malloc(sizeof(T)*(this->size + 1));

    for (int i = 0; i < this->size; ++i){
        newData->setData(tmp->getData()[i], i);
    }
    newData->setData(dataToAdd, this->size);

    free(tmp->data);
    free(this->data);

    return newData;
};
