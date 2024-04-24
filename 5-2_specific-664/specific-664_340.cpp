Array2<T> *addData(T dataToAdd){
    Array2 <T> *tmp = new Array2<T>(this->size);
    tmp->data = this->getData();
    
    Array2 <T> *newData = new Array2<T>(this->size + 1);
    newData->data = (T *) malloc(sizeof(T)*(this->size + 1));
    
    // Rest of the code...
}
for (int i = 0; i < tmp->getSize(); ++i){
    newData->setData(tmp->getData()[i], i);
}

newData->setData(dataToAdd, tmp->getSize());
free(tmp->data); // Free the data array inside tmp
free(this->data); // Free the current data array
