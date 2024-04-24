Array2<T>* addData(T dataToAdd){
    Array2<T>* tmp = new Array2<T>(*this); // Copy the current array
    Array2<T>* newData = new Array2<T>(this->size + 1);

    // Copy existing data
    memcpy(newData->data, tmp->data, sizeof(T) * tmp->size);
    // Add new data
    newData->data[tmp->size] = dataToAdd;

    delete tmp; // Free the temporary array's memory

    return newData;
};
