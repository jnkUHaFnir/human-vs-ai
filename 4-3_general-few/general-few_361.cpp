Array2<T> *addData(T dataToAdd) {
    Array2<T> *tmp = this;
    T* tmpData = tmp->getData();

    Array2<T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < tmp->getSize(); ++i) {
        newData->setData(tmpData[i], i);     
    }

    newData->setData(dataToAdd, this->size);

    free(tmp->data);
    free(this->data);

    return newData;
}
