class Solution {
public:

    ListNode* solve(ListNode* head) {

        // Last node
        if (head == NULL || head->next == NULL)
            return head;

        // Process everything to the right
        head->next = solve(head->next);

        // If next node is greater, remove current node
        if (head->next != NULL &&
            head->next->val > head->val) {
            return head->next;
        }

        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        return solve(head);
    }
};
