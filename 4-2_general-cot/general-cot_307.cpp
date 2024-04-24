template<typename T>
class Array2{
public:
    Array2(int size){
        this->size = size;
        this->data = (T *)malloc(sizeof(T) * size);
    }

    Array2<T> *addData(T dataToAdd){
        Array2<T> *newData = new Array2<T>(this->size + 1);

        for (int i = 0; i < this->size; ++i){
            newData->data[i] = this->data[i];
        }

        newData->data[this->size] = dataToAdd;

        return newData;
    }

    ~Array2(){
        free(this->data);
    }

    // Other member functions remain the same

private:
    int size;
    T* data;
};
