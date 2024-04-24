Array2<T> *addData(T dataToAdd){
    Array2<T> *tmp = new Array2<T>(this->size);
    tmp->data = this->getData();
    Array2<T> *newData = new Array2<T>(this->size + 1);
    newData->data = (T *) malloc(sizeof(T) * (this->size + 1));

    for (int i = 0; i < tmp->getSize() + 1; ++i){
        if (i < tmp->getSize()){
            newData->setData(tmp->getData()[i], i);
        }
        else{
            newData->setData(dataToAdd, i);
        }
    }

    free(tmp->data);
    free(this->data);
    return newData;
}
