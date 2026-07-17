class Node{
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(){
        key = -1;
        value = -1;
        next = prev = nullptr;
    }

    Node(int k, int val){
        key = k;
        value = val;
        next = prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp; //for O(1)
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        //basically pointers change krdo
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        //change pointers;
        node->next = currAfterHead;
        head->next = node;
        node->prev = head;
        currAfterHead->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1; //not in lru

        Node* node = mpp[key]; //get node from mpp;
        deleteNode(node);
        insertAfterHead(node);
        //node becomes recent, hence shifted next to head
        return node->value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return; 
        
        //if in mpp, update
        if (mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
            //update and then put next to head;
        }
        else{
            if (mpp.size() == cap){//means need to evict LR
                Node* node = tail->prev;
                mpp.erase(node->key); //mpp se bhi uda do
                deleteNode(node);
                //this node can be deleted too
                delete node;
            }
            //simply create node and insert
            Node* node = new Node(key, value);
            mpp[key] = node; //map me dalo
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */