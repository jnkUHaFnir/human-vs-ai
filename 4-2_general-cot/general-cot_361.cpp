Array2<T>* addData(T dataToAdd){
    Array2<T>* tmp = new Array2<T>(*this); // Create a copy of the current object
    Array2<T>* newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < tmp->getSize(); ++i){
        newData->setData(tmp->getData()[i], i);
    }

    newData->setData(dataToAdd, tmp->getSize());

    delete tmp; // Cleanup the temporary object
    delete[] this->data; // Free the old data

    return newData;
}
~Array2(){
    delete[] this->data;  
}
