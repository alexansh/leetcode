/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        int cnt = 0;

        while (curr && cnt < k) {
            curr = curr->next;
            cnt++;
        }

        if (cnt < k)
            return head;

        curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        cnt = 0;

        while (curr && cnt < k) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            cnt++;
        }

        if (next)
            head->next = reverseKGroup(next, k);

        return prev;
    }
};
