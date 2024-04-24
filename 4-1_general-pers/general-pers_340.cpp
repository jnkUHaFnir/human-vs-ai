Array2<T>* addData(T dataToAdd) {
    Array2<T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < this->size; ++i) {
        newData->setData(this->getData()[i], i);
    }

    newData->setData(dataToAdd, this->size);

    return newData;
}
