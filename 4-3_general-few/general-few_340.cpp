Array2<T> *addData(T dataToAdd){
    Array2<T> *newData = new Array2<T>(this->size + 1);

    T *tmp = this->getData();
    T *newDataPtr = newData->getData();

    for (int i = 0; i < this->size; ++i){
        newDataPtr[i] = tmp[i];
    }
    
    newDataPtr[this->size] = dataToAdd;

    return newData;
}
