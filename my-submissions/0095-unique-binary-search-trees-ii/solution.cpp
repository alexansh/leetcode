class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;

        // No values -> empty subtree
        if (start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        // Try every value as root
        for (int i = start; i <= end; i++) {

            // Generate all left subtrees
            vector<TreeNode*> left = solve(start, i - 1);

            // Generate all right subtrees
            vector<TreeNode*> right = solve(i + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {

                    TreeNode* root = new TreeNode(i);

                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};
