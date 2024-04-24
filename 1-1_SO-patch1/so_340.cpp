    for (int i = 0; i < tmp->getSize(); ++i){
        if (i < tmp->getSize()){
            newData->data[i] = tmp->data[i]; // you were right here
        }
    }
    newData->data[tmp->getSize()] = dataToAdd;