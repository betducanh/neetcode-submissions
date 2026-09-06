class MyHashSet {
private:
    vector<int> ourSet;
public:
    MyHashSet() {}
    
    void add(int key) {
        if (ourSet.empty()) {
            ourSet.push_back(key);
            return;
        }

        for (int i : ourSet) {
            if (i == key) return;
        }
        ourSet.push_back(key);
    }
    
    void remove(int key) {
        for (int i = 0; i < ourSet.size(); i++) {
            if (ourSet[i] == key) {
                ourSet.erase(ourSet.begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        for (int i : ourSet) {
            if (i == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */