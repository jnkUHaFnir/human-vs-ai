Array2<T> *addData(T dataToAdd){
    Array2 <T> *tmp = new Array2<T>(*this); // Create a new Array2 object and copy the data
    Array2 <T> *newData = new Array2<T>(this->size + 1); // Create a new Array2 object with increased size

    for (int i = 0; i < tmp->size; ++i){
        newData->setData(tmp->getData()[i], i);
    }

    newData->setData(dataToAdd, this->size); // Add the new data at the end

    delete[] tmp->data; // Free the memory allocated for the temporary object's data
    delete[] this->data; // Free the current object's data

    return newData;
};
