struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class MyCircularQueue {
private:
    int size;
    int count = 0;
    Node* front;
    Node* rear;
public:
    MyCircularQueue(int k) {
        size = k;
        front = nullptr;
        rear = nullptr;
    }
    
    bool enQueue(int value) {
        if (count == size) return false;

        if (count) {
            rear->next = new Node(value, front);
            rear = rear->next;
        }
        
        else {
            front = new Node(value);
            rear = front;
            rear->next = front;
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if (!count) return false;

        Node* temp = front;
        rear->next = front->next;
        front = front->next;
        delete temp;
        count--;
        return true;
    }
    
    int Front() {
        if (!count) return -1;
        return front->data;
    }
    
    int Rear() {
        if (!count) return -1;
        return rear->data;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
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