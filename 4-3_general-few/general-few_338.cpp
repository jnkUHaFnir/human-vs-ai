#include <unordered_map>
#include <string>

struct Node {
    unsigned long long A;
    std::string B;
    struct Node* next;
    struct Node* prev;
};

class DataStore {
private:
    std::unordered_map<unsigned long long, Node*> map;
    Node* head;
    Node* tail;

public:
    DataStore() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void set(unsigned long long a, const std::string& b) {
        Node* newNode = new Node();
        newNode->A = a;
        newNode->B = b;

        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;

        map[a] = newNode;
    }

    std::string get(unsigned long long a) {
        if (map.find(a) != map.end()) {
            return map[a]->B;
        }
        return ""; // or any default value
    }
};

int main() {
    DataStore ds;
    ds.set(123, "abc");
    ds.set(456, "def");

    unsigned long long key = 123;
    std::string value = ds.get(key);
    if (!value.empty()) {
        std::cout << "Value for key " << key << ": " << value << std::endl;
    } else {
        std::cout << "Value not found for key " << key << std::endl;
    }

    return 0;
}
