// Definition for a binary tree node.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            long long mini = q.front().second;
            long long first, last;

            for (int i = 0; i < size; i++) {

                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;

                long long idx = temp.second - mini;

                if (i == 0)
                    first = idx;

                if (i == size - 1)
                    last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};
