Array2<T> *addData(T dataToAdd) {
    Array2<T> *tmp = new Array2<T>(*this);
    
    Array2<T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < tmp->getSize(); ++i) {
        newData->setData(tmp->getData()[i], i);
    }

    newData->setData(dataToAdd, tmp->getSize());

    delete tmp;
    free(this->data); // Only free the current object's data

    return newData;
}
