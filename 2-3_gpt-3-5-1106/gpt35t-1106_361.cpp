Array2<T>* addData(T dataToAdd){
    Array2<T> *tmp = new Array2<T>(*this);
    Array2<T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < tmp->getSize(); ++i){
        newData->setData(tmp->getData()[i], i);
    }
    newData->setData(dataToAdd, this->size);

    delete tmp;
    delete this;
    return newData;
}
