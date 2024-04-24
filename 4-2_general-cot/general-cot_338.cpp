#include <iostream>
#include <unordered_map>
#include <string>

struct Node {
    unsigned long long key;
    std::string value;
    Node* prev;
    Node* next;
};

class LRUCache {
private:
    std::unordered_map<unsigned long long, Node*> map;
    Node* head;
    Node* tail;
    int capacity;
    
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    void set(unsigned long long key, std::string value) {
        if (map.find(key) != map.end()) {
            // Update the existing node
            Node* node = map[key];
            node->value = value;
            // Move the node to the front of the list
            moveToHead(node);
        } else {
            Node* new_node = new Node();
            new_node->key = key;
            new_node->value = value;
            map[key] = new_node;
            addToHead(new_node);
            if (map.size() > capacity) {
                // Remove the least recently used node
                Node* to_remove = tail->prev;
                removeFromList(to_remove);
                map.erase(to_remove->key);
                delete to_remove;
            }
        }
    }
    
    std::string get(unsigned long long key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            // Move the node to the front of the list
            moveToHead(node);
            return node->value;
        }
        return "Key not found";
    }
    
private:
    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeFromList(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Node* node) {
        removeFromList(node);
        addToHead(node);
    }
};

int main() {
    LRUCache cache(5);
    cache.set(1, "One");
    cache.set(2, "Two");
    cache.set(3, "Three");
    
    std::cout << "Get result: " << cache.get(2) << std::endl;
    std::cout << "Get result: " << cache.get(4) << std::endl;
    
    return 0;
}
