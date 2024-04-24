Array2<T> *addData(T dataToAdd){
    Array2<T> *tmp = new Array2<T>(this->size);
    for (int i = 0; i < this->size; ++i){
        tmp->setData(this->getData()[i], i);
    }

    Array2<T> *newData = new Array2<T>(this->size + 1);
    for (int i = 0; i < this->size; ++i){
        newData->setData(tmp->getData()[i], i);
    }
    newData->setData(dataToAdd, this->size);

    delete tmp;
    free(this->data); // Free the old data
    
    return newData;
};
