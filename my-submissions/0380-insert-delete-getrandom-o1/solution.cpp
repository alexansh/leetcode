class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.count(val))
            return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;

        int index = mp[val];
        int lastElement = nums.back();

        nums[index] = lastElement;
        mp[lastElement] = index;

        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};
