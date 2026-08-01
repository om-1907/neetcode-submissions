class MyCircularQueue {
private:
    vector<int>queue;
    int size;
    int cap;
    int f,r;
public:
    MyCircularQueue(int k) {
        queue=vector<int>(k);
        cap=k;
        size=0;
        f=0;r=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r=(r+1)%cap;
        queue[r]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        f=(f+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:queue[f];
    }
    
    int Rear() {
        return isEmpty()? -1:queue[r];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */