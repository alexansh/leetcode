/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = head;

        while (curr) {
            Node* next = curr->next;

            // If current node has a child
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                // Connect current -> child
                curr->next = childHead;
                childHead->prev = curr;

                // Connect childTail -> next
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                curr->child = nullptr;
                last = childTail;
            } else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }

    Node* flatten(Node* head) {
        if (!head)
            return head;

        dfs(head);
        return head;
    }
};
