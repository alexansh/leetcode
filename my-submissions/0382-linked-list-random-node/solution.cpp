/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int ans = 0;
        int count = 0;

        ListNode* curr = head;

        while (curr) {
            count++;

            // Replace answer with probability 1/count
            if (rand() % count == 0)
                ans = curr->val;

            curr = curr->next;
        }

        return ans;
    }
};
