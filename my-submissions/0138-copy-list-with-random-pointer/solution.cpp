class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create copy nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        
        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        // Step 3: Separate lists
        Node* dummy = new Node(0);
        Node* copy = dummy;
        curr = head;
        
        while (curr) {
            copy->next = curr->next;
            curr->next = curr->next->next;
            
            copy = copy->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
