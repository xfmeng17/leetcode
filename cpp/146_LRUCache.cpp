class DLinkedList {
public:
    int key;
    int val;
    DLinkedList* prev;
    DLinkedList* next;
    
    DLinkedList(int _key, int _val) {
        key = _key;
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
        head = new DLinkedList(0, 0);
        tail = new DLinkedList(0, 0);
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
        Dump(head, tail);

        return val;
    }
    
    void put(int key, int val) {
        if (map.find(key) != map.end()) {
            Delete(map[key]);
            map[key] = Add(head, key, val);
            Dump(head, tail);
            return;
        }

        if (size < cap) {
            map[key] = Add(head, key, val);
            Dump(head, tail);
            return;
        }

        int elimKey = Eliminate(head, tail);
        map.erase(elimKey);
        map[key] = Add(head, key, val);
        Dump(head, tail);
        return;
    }
    
    DLinkedList* Add(DLinkedList* head, int key, int val) {
        DLinkedList* node = new DLinkedList(key, val);
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
    int Eliminate(DLinkedList* head, DLinkedList* tail) {
        DLinkedList* curr = tail->prev;
        if (curr == head) {
            return 0;
        }
        int key = curr->key;
        DLinkedList* prev = curr->prev;
        prev->next = tail;
        tail->prev = prev;
        size--;
        delete curr;
        return key;
    }
    void Dump(DLinkedList* head, DLinkedList* tail) {
        return;
        while (head->next != tail) {
            printf("p=%p, key=%d, val=%d\n", head->next, head->next->key, head->next->val);
            head = head->next;
        }
        printf("***size=%d***\n", size);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,val);
 */