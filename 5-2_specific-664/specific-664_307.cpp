Array2<T>* addData(T dataToAdd){
    Array2<T>* tmp = new Array2<T>(*this); // Create a copy of the current instance
    Array2<T>* newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < this->size; ++i){
        newData->setData(tmp->getData()[i], i);
    }
    newData->setData(dataToAdd, this->size); // Add new data at the end

    free(tmp->data); // Free temporary data

    return newData;
};
