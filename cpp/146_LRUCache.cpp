class DLinkedList {
public:
    int val;
    DLinkedList* prev;
    DLinkedList* next;
    
    DLinkedList(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
private:
    int cap;
    int size;
    DLinkedList* head;
    DLinkedList* tail;
    unordered_map<int, DLinkedList*> map;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new DLinkedList(0);
        tail = new DLinkedList(0);
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache() {
        delete head;
        delete tail;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int val = map[key]->val;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (size < cap) {
            map[key] = Add(head, value);
            return;
        }

        if (map.find(key) != map.end()) {
            Delete(map[key]);
            map[key] = Add(head, value);
        } else {
            Eliminate(head, tail);
            map[key] = Add(head, value);
        }

        return;
    }
    
    DLinkedList* Add(DLinkedList* head, int val) {
        DLinkedList* node = new DLinkedList(val);
        DLinkedList* first = head->next;
        first->prev = node;
        node->next = first;
        node->prev = head;
        head->next = node;
        size++;
        return node;
    }
    void Delete(DLinkedList* node) {
        DLinkedList* prev = node->prev;
        DLinkedList* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
        delete node;
        return;
    }
    void Eliminate(DLinkedList* head, DLinkedList* tail) {
        DLinkedList* curr = tail->prev;
        if (curr == head) {
            return;
        }
        DLinkedList* prev = curr->prev;
        prev->next = tail;
        tail->prev = prev;
        size--;
        delete curr;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */