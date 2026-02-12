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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;

        if(root == NULL){
            return postorder;
        }

        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            postorder.push_back(top->val);

            if(top->left != NULL){
                st.push(top->left);
            }

            if(top->right != NULL){
                st.push(top->right);
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};
