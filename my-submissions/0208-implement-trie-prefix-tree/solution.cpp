class Trie {
    struct Node {
        Node* links[26] = {};
        bool end = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->links[c - 'a'])
                node->links[c - 'a'] = new Node();
            node = node->links[c - 'a'];
        }
        node->end = true;
    }

    bool search(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->links[c - 'a'])
                return false;
            node = node->links[c - 'a'];
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->links[c - 'a'])
                return false;
            node = node->links[c - 'a'];
        }
        return true;
    }
};
