class LRUCache {
int capacity;
unordered_map<int,int> ourMap;
vector<int> ourKey;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = find(ourKey.begin(), ourKey.end(), key);

        if (it != ourKey.end()) {
            ourKey.erase(it);
            ourKey.push_back(key);
            return ourMap[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (ourKey.size() < capacity) {
            auto it = find(ourKey.begin(), ourKey.end(), key);

            if (it != ourKey.end()) ourKey.erase(it);

            ourKey.push_back(key);
            ourMap[key] = value;
        }

        else {
            auto it = find(ourKey.begin(), ourKey.end(), key);

            if (it != ourKey.end()) {
                ourKey.erase(it);
                ourKey.push_back(key);
                ourMap[key] = value;
            }

            else {
                ourKey.erase(ourKey.begin());
                ourKey.push_back(key);
                ourMap[key] = value;
            }
        }
    }
};
