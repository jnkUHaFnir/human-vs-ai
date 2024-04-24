Array2<T> *addData(T dataToAdd) {
    Array2<T> *tmp = this; // Storing a reference to the current object
    Array2<T> *newData = new Array2<T>(this->size + 1); // Creating a new Array2 object

    for (int i = 0; i < tmp->getSize(); ++i) {
        newData->setData(tmp->getData()[i], i);
    }

    newData->setData(dataToAdd, tmp->getSize()); // Adding the new data at the end

    return newData;
}
