Array2<T>* addData(T dataToAdd) {
    Array2<T>* newData = new Array2<T>(this->size + 1);

    // Copy data from current object to newData
    for (int i = 0; i < this->size; ++i) {
        newData->setData(this->data[i], i);
    }
    // Add the new data to the end
    newData->setData(dataToAdd, this->size);

    return newData;
};
