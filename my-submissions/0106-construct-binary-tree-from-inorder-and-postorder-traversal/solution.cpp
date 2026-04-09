/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inMap;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return helper(postorder, 0, n - 1);
    }

    TreeNode* helper(vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inMap[rootVal];

        // IMPORTANT: build right subtree first
        root->right = helper(postorder, mid + 1, right);
        root->left  = helper(postorder, left, mid - 1);

        return root;
    }
};
