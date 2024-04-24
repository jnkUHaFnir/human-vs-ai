Array2<T> *addData(T dataToAdd) {
    Array2 <T> *newData = new Array2<T>(this->size + 1);

    for (int i = 0; i < this->size; ++i) {
        newData->setData(this->data[i], i);
    }

    newData->setData(dataToAdd, this->size);  // Add the new data to the end

    return newData;
}
Array2<int> *testArray3 = new Array2<int>(5);
Array2<int> *testArray4;
testArray3->initArray();
testArray3->printArray();
testArray4 = testArray3->addData(7);
testArray4->printArray();

delete testArray3;
delete testArray4;
