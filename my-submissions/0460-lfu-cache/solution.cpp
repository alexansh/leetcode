class LFUCache {
public:
    int cap, minFreq;

    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyValFreq[key].second;

        freqList[freq].erase(pos[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        keyValFreq[key].second++;

        freqList[freq + 1].push_back(key);
        pos[key] = --freqList[freq + 1].end();
    }

    int get(int key) {
        if (!keyValFreq.count(key))
            return -1;

        updateFreq(key);
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyValFreq.count(key)) {
            keyValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyValFreq.size() == cap) {
            int evict = freqList[minFreq].front();

            freqList[minFreq].pop_front();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyValFreq.erase(evict);
            pos.erase(evict);
        }

        keyValFreq[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
