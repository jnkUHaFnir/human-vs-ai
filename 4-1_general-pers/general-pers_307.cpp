Array2<T> *addData(T dataToAdd) {
    Array2 <T> *tmp = new Array2<T>(this->size);
    T* tmpData = tmp->getData();
    T* newData = (T *)malloc(sizeof(T) * (this->size + 1));

    for (int i = 0; i < tmp->getSize(); ++i) {
        newData[i] = this->getData()[i];
    }
    newData[this->size] = dataToAdd;

    free(tmpData);
    free(this->data);

    this->data = newData;
    this->size++;

    return this;
}
