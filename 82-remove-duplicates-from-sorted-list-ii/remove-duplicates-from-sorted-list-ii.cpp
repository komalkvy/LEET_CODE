class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to simplify edge case deletions
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;
        ListNode* mover = head;

        while (mover && mover->next) {
            if (mover->val == mover->next->val) {
                int dupVal = mover->val;
                // Skip all nodes with dupVal
                while (mover && mover->val == dupVal) {
                    mover = mover->next;
                }
                temp->next = mover;  // Skip duplicates
            } else {
                temp = mover;
                mover = mover->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;  // Clean up dummy node
        return result;
    }
};