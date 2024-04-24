Array2<T> *addData(T dataToAdd){
    Array2 <T> *tmp = new Array2<T>(*this); // Create a new Array2 object as a copy of the current object
    Array2 <T> *newData = new Array2<T>(this->size + 1); // Create a new Array2 object with increased size

    for (int i = 0; i < tmp->getSize(); ++i){
        newData->setData(tmp->getData()[i], i); // Copy existing data to new array
    }

    newData->setData(dataToAdd, this->size); // Add new data at the end

    delete tmp; // Free memory of the temporary object

    return newData;
}
