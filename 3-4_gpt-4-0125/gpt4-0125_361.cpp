Array2<T> *addData(T dataToAdd){
    Array2<T> *newData = new Array2<T>(this->size + 1); // Allocate memory for the new object

    // Copy existing data
    for (int i = 0; i < this->size; ++i){
        newData->setData(this->data[i], i);
    }

    // Add the new data
    newData->setData(dataToAdd, this->size);

    // Return the new object
    return newData;
};
