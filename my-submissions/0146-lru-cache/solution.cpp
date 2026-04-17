class LRUCache {
private:
    int capacity;
    
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        
        auto it = mp[key];
        int value = it->second;
        
        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            dll.erase(mp[key]);
        }
        else if (dll.size() == capacity) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
        
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
