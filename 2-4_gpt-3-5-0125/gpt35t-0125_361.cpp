Array2<T> *addData(T dataToAdd){
    Array2 <T> *tmp = new Array2<T>(this->size);
    tmp->setData(this->getData(), this->size);

    Array2 <T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < this->size + 1; ++i){
        if (i < this->size){
            newData->setData(tmp->getData()[i], i);
        }
        else{
            newData->setData(dataToAdd, i);
        }
    }

    // free the old data after copying
    free(this->data);

    return newData;
}
