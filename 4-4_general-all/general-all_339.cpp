#include <unordered_map>
#include <string>
using namespace std;

struct Data {
    unsigned long long A;
    string B;
    Data* prev;
    Data* next;
};

class DataStore {
private:
    unordered_map<unsigned long long, Data*> dataMap;
    Data* head;
    Data* tail;

public:
    DataStore() : head(nullptr), tail(nullptr) {}

    void set(unsigned long long A, const char* B) {
        // Check if data with key A already exists
        if (dataMap.find(A) != dataMap.end()) {
            // Data already exists, update B
            dataMap[A]->B = B;
            return;
        }

        // Allocate memory for new Data
        Data* newData = new Data{A, B, nullptr, nullptr};

        // Update hash map with the new data
        dataMap[A] = newData;

        // Update linked list
        if (!head) {
            head = newData;
            tail = newData;
        } else {
            newData->prev = tail;
            tail->next = newData;
            tail = newData;
        }
    }

    string get(unsigned long long A) {
        if (dataMap.find(A) == dataMap.end()) {
            return "Key not found";
        }
        
        return dataMap[A]->B;
    }
};

int main() {
    DataStore ds;

    ds.set(123, "Hello");
    ds.set(456, "World");

    cout << ds.get(123) << endl;  // Output: Hello
    cout << ds.get(456) << endl;  // Output: World
    cout << ds.get(789) << endl;  // Output: Key not found

    return 0;
}
