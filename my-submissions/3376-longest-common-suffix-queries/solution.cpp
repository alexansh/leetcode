class Solution {
public:

    struct TrieNode {
        int child[26];
        int idx;

        TrieNode() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<TrieNode> trie;

    void insert(string &word, int index,
                vector<string>& wordsContainer) {

        int node = 0;

        if (trie[node].idx == -1 ||
            wordsContainer[index].size() <
            wordsContainer[trie[node].idx].size()) {

            trie[node].idx = index;
        }

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            if (trie[node].idx == -1 ||
                wordsContainer[index].size() <
                wordsContainer[trie[node].idx].size()) {

                trie[node].idx = index;
            }
        }
    }

    int search(string &word) {

        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (string &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};
