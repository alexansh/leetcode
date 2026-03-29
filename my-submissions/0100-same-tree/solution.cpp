class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both null → same
        if (!p && !q) return true;

        // one null or values different → not same
        if (!p || !q || p->val != q->val) return false;

        // check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
