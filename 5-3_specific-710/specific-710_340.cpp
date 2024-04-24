template<typename T>
Array2<T> *addData(T dataToAdd) {
    Array2<T> *newData = new Array2<T>(this->size + 1); // Allocate memory for a new array with increased size

    // Copy data from the current array to the new array
    for (int i = 0; i < this->size; ++i) {
        newData->setData(this->getData()[i], i);
    }

    // Add the new data to the end of the new array
    newData->setData(dataToAdd, this->size);

    return newData;
}
