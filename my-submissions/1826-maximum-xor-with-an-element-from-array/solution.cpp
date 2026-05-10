class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }

            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;

        if (!node->child[0] && !node->child[1])
            return -1;

        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // prefer opposite bit
            if (node->child[1 - bit]) {
                maxXor |= (1 << i);
                node = node->child[1 - bit];
            }
            else {
                node = node->child[bit];
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> offlineQueries;

        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back(
                {queries[i][1], queries[i][0], i}
            );
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> ans(queries.size());

        int idx = 0;

        for (auto &q : offlineQueries) {

            int m = q[0];
            int x = q[1];
            int queryIndex = q[2];

            while (idx < nums.size() && nums[idx] <= m) {
                trie.insert(nums[idx]);
                idx++;
            }

            ans[queryIndex] = trie.getMaxXor(x);
        }

        return ans;
    }
};
