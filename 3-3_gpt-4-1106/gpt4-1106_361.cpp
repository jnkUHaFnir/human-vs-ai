template<typename T>
Array2<T>* Array2<T>::addData(T dataToAdd) {
    Array2<T>* tmp; // Here, you declare a pointer but do not initialize it.

    // This is undefined behavior because tmp is not pointing to a valid object.
    tmp->data = this->getData();

    Array2<T>* newData;
    // Also undefined behavior because newData is not initialized.
    newData->data = (T *) malloc(sizeof(T)*(this->size + 1));

    for (int i = 0; i < tmp->getSize() + 1; ++i) {
        if (i < tmp->getSize()) {
            newData->setData(tmp->getData()[i], i);
        }
        else {
            newData->setData(dataToAdd, i);
        }
    }

    // You are freeing an uninitialized pointer's data member, which is undefined.
    free(tmp->data);
    free(this->data); // Also, you shouldn't free this->data here without reassigning it.
    return newData;
}
template<typename T>
Array2<T>* Array2<T>::addData(T dataToAdd) {
    // Create a new dynamic array with additional space for the new element.
    Array2<T>* newData = new Array2<T>(this->size + 1);

    // Copy the existing data to the new array.
    for (int i = 0; i < this->size; ++i) {
        newData->setData(this->getData()[i], i);
    }

    // Add the new element.
    newData->setData(dataToAdd, this->size);

    // Free the old memory.
    free(this->data);

    // Update the instance to point to the new array and size.
    this->data = newData->data;
    this->size += 1;

    // Since we've transferred ownership of the data to this, we need to set newData's data to nullptr
    // Otherwise, it will be freed when newData is destroyed.
    newData->data = nullptr;

    return this; // We return the current object, which now contains the new data.
}
template<typename T>
Array2<T>::~Array2() {
    if (this->data) {
        free(this->data);
    }
}
