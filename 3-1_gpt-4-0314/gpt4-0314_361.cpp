Array2<T> *addData(T dataToAdd){
    Array2 <T> *tmp = new Array2<T>(this->size);
    tmp->data = this->getData();
    Array2 <T> *newData = new Array2<T>(this->size + 1);
    newData->data = (T *) malloc(sizeof(T)*(this->size + 1));

    for (int i = 0; i < tmp->getSize() + 1; ++i){
        if (i < tmp->getSize()){
            //newData->data[i] = tmp->data[i];
            newData->setData(tmp->getData()[i], i);
        }
        else{
            //newData->data[i] = dataToAdd;
            newData->setData(dataToAdd, i);
        }
    }

    free(tmp->data);
    delete tmp; // Since tmp was it was allocated using 'new', use delete to deallocate the memory
    return newData;
};
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

template<typename T>
class Array2{
public:
    Array2(int size){
        this->size = size;
        data = (T *) malloc(sizeof(T)*size);
    };
    Array2<T> *addData(T dataToAdd){
        Array2 <T> *tmp = new Array2<T>(this->size);
        tmp->data = this->getData();
        Array2 <T> *newData = new Array2<T>(this->size + 1);
        newData->data = (T *) malloc(sizeof(T)*(this->size + 1));

        for (int i = 0; i < tmp->getSize() + 1; ++i){
            if (i < tmp->getSize()){
                //newData->data[i] = tmp->data[i];
                newData->setData(tmp->getData()[i], i);
            }
            else{
                //newData->data[i] = dataToAdd;
                newData->setData(dataToAdd, i);
            }
        }

        free(tmp->data);
        delete tmp;
        return newData;
    };
    ~Array2(){
        free(this->data);  
    };
    void initArray(){
        for (int i = 0; i < this->size; ++i){
            //this->data[i] = i;
            this->setData(i, i);
        }
    };
    void printArray(){
        //ostringstream oss;
        string answer = "";

        for (int i = 0; i < this->size; ++i){
            //oss << this->data[i] + " ";
            cout << this->data[i] << " ";
        }

        //answer = oss.str();

        cout << answer << endl;
    };
    T* getData(){
        return this->data;
    }
    int getSize(){
        return this->size;
    }
    void setData(T data, int index){
        this->getData()[index] = data;
    }
private:
    int size;
    T* data;
};
