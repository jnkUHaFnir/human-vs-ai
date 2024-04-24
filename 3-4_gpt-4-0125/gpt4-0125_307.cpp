template<typename T>
Array2<T> *addData(T dataToAdd){
    // Allocate memory for the new Array2 object
    Array2<T> *newArray = new Array2<T>(this->size + 1);
    
    // Copy existing data to the new array
    for (int i = 0; i < this->size; ++i) {
        newArray->setData(this->data[i], i);
    }
    
    // Add the new data to the end of the new array
    newArray->setData(dataToAdd, this->size);
    
    // Return the new array with additional data
    return newArray;
}
