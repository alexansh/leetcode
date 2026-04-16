/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* level = root;

        while (level->left) {  // since perfect tree
            Node* curr = level;

            while (curr) {
                // connect left -> right
                curr->left->next = curr->right;

                // connect right -> next node's left
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            level = level->left; // move to next level
        }

        return root;
    }
};
