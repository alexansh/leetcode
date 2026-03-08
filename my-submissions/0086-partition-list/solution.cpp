class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* lessHead = NULL;
        ListNode* lessTail = NULL;

        ListNode* greaterHead = NULL;
        ListNode* greaterTail = NULL;

        while (head) {
            if (head->val < x) {
                if (!lessHead) {
                    lessHead = lessTail = head;
                } else {
                    lessTail->next = head;
                    lessTail = head;
                }
            } 
            else {
                if (!greaterHead) {
                    greaterHead = greaterTail = head;
                } else {
                    greaterTail->next = head;
                    greaterTail = head;
                }
            }

            head = head->next;
        }

        if (greaterTail) 
            greaterTail->next = NULL;

        if (!lessHead) 
            return greaterHead;

        lessTail->next = greaterHead;

        return lessHead;
    }
};
