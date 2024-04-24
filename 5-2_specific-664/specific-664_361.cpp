Array2<T> *addData(T dataToAdd){
    Array2<T> *newData = new Array2<T>(size + 1); // Allocate memory for new array
    T* tmpData = this->getData(); // Get data from current array

    for (int i = 0; i < size; ++i){
        newData->setData(tmpData[i], i); // Copy data from current array to new array
    }
    newData->setData(dataToAdd, size); // Add new data at the end

    return newData;
};
