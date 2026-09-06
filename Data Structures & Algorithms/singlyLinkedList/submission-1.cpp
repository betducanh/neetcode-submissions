#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}

    Node(int val, Node* nxt) : data(val), next(nxt) {}
};

class LinkedList {
private:
    int length;
    Node* head;
    Node* tail;

public:
    LinkedList() : length(0), head(nullptr), tail(nullptr) {}

    int get(int index) {
        if (index < 0 || index >= length) return -1;

        Node* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val, head);
        head = newHead;

        if (length == 0) {
            tail = head;
        }

        length++;
    }
    
    void insertTail(int val) {
        Node* newTail = new Node(val);

        if (length == 0) {
            head = newTail;
            tail = newTail;
        } else {
            tail->next = newTail;
            tail = newTail;
        }

        length++;
    }

    bool remove(int index) {
        if (index < 0 || index >= length) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;

            length--;

            if (length == 0) {
                tail = nullptr;
            }

            return true;
        }

        Node* prev = head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        Node* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;

        if (nodeToDelete == tail) {
            tail = prev;
        }

        delete nodeToDelete;
        length--;

        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head;

        while (curr != nullptr) {
            res.push_back(curr->data);
            curr = curr->next;
        }

        return res;
    }

    ~LinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};