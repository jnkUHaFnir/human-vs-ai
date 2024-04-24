Array2<T>* addData(T dataToAdd){
    Array2<T>* tmp = new Array2<T>(this->size);
    memcpy(tmp->data, this->data, sizeof(T) * this->size);

    Array2<T>* newData = new Array2<T>(this->size + 1);
    memcpy(newData->data, this->data, sizeof(T) * this->size);
    newData->data[this->size] = dataToAdd;

    return newData;
};
