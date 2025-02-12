class LRUCache {
private:
    // Need a double ended linked list to meet time complexity
    int size = 0;
    int capacity = 0;
    struct Node {
        Node* next;
        Node* rNext;
        int key;
        int val;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> nodeMap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!nodeMap.contains(key)) {
            return -1;
        }
        // cout << "Using " << key << endl << endl;
        // The key becomes the most recently used, put to the head of the LL. 
        Node* prev = nodeMap[key]->rNext;
        Node* curr = nodeMap[key];
        if (curr == nullptr) {
            return -1;
        }
        if (prev == nullptr) {
            // It was already at the head of the LL
            return curr->val;
        }
        // Otherwise, need to move this node to the head of the LL.
        if (curr->next == nullptr) {
            // If it is at the end, we need to update the tail.
            tail = prev;
        }
        Node* currNext = curr->next;

        head->rNext = curr;

        curr->next = head;
        head = curr;

        head->rNext = nullptr;

        prev->next = currNext;
        if (currNext != nullptr) {
            currNext->rNext = prev;
        }
        return curr->val;
    }

    void printLL() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << "(key: " << curr->key << " val: " << curr->val << ")";
            curr = curr->next;
        }
        cout << endl;
        cout << endl;
    }
    
    void put(int key, int value) {
        // cout << "Adding key: " << key << " val: " << value << endl;
        // printLL();
        // The key becomes the most recently used, put to the head of the LL. 
        if (!nodeMap.contains(key)) {
            // It didn't already exist in the LL
            Node* newNode = new Node( head, nullptr, key, value );
            if (head != nullptr) {
                head->rNext = newNode;
            }
            if (tail == nullptr) {
                // This is the first ever node to the added to the LL.
                tail = newNode;
            }
            
            head = newNode;
            nodeMap[key] = newNode;
            if (size < capacity) {
                size++;
                return;
            } else {
                // Need to remove the entry at the end of the LL.
                // Since min capacity is 1, we are guaranteed that this case will have length at least 2.
                Node* secLast = tail->rNext;

                nodeMap.erase(tail->key);
                cout << "erasing: " << tail->key << endl;
                delete secLast->next;
                secLast->next = nullptr;

                tail = secLast;

                return;
            }
        }
        // It already exists in the LL
        Node* prev = nodeMap[key]->rNext;
        Node* curr = nodeMap[key];
        curr->val = value;
        if (prev == nullptr) {
            // It is already the head of the LL
            return;
        }
        // Otherwise, need to move this node to the head of the LL.
        if (curr->next == nullptr) {
            // If it is at the end, we need to update the tail.
            tail = prev;
        }
        Node* currNext = curr->next;

        head->rNext = curr;

        curr->next = head;
        head = curr;

        head->rNext = nullptr;

        prev->next = currNext;
        if (currNext != nullptr) {
            currNext->rNext = prev;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */