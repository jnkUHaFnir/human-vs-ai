    for (int i = 0; i < tmp->size; ++i){
        newData->data[i] = tmp->data[i]; // you were right here
    }
    newData->data[tmp->size] = dataToAdd;