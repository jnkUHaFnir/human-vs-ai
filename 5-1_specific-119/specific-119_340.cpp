Array2<T> *addData(T dataToAdd) {
    Array2<T> *tmp = new Array2<T>(this->size);
    std::memcpy(tmp->data, this->data, sizeof(T) * this->size);

    Array2<T> *newData = new Array2<T>(this->size + 1);
    std::memcpy(newData->data, tmp->data, sizeof(T) * this->size);
    newData->data[this->size] = dataToAdd;

    delete tmp;
    free(this->data);
    return newData;
}
