/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root) {

            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            
            // both nodes in right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            
            // split occurs here
            else {
                return root;
            }
        }
        
        return NULL;
    }
};
