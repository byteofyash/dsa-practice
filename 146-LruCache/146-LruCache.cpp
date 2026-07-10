// Last updated: 7/11/2026, 2:54:25 AM
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
         next = nullptr;
    }
};

class LRUCache {

public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    void removeNode(Node* node) {
        Node* A = node->prev;
        Node* B = node->next;
        A->next = B;
        B->prev = A;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void insertAfterHead(Node* node) {
        Node* X = head->next;
        head->next = node;
        X->prev = node;

        node->prev = head;
        node->next = X;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        removeNode(mp[key]);
        insertAfterHead(mp[key]);

        return mp[key]->value;
    }

    void put(int key, int value) {
        //update if present
        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            removeNode(mp[key]);
            insertAfterHead(mp[key]);

        }

        else {
            //create if not present

            // if size greater than capacity
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* node = new Node(key, value);
            insertAfterHead(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */