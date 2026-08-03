class Node{
public:
    int key,val;
    Node* prev;Node*next;
     Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*>mpp;
    int cap;
    Node* head;
    Node* tail;
    void remove(Node* node){
        Node* prv=node->prev;
        Node* nxt=node->next;
        prv->next=nxt;
        nxt->prev=prv;
    }
    void insert(Node* node){
        Node* currafterhead=head->next;
        head->next=node;
        node->next=currafterhead;
        node->prev=head;
        currafterhead->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            remove(node);
            mpp.erase(key);
            delete node;
        }
        Node* newnode=new Node(key,value);
        mpp[key]=newnode;
        insert(newnode);
        if(mpp.size()>cap){
            Node* lru=tail->prev;
            remove(lru);
            mpp.erase(lru->key);
            delete lru;
        }
    }
};
