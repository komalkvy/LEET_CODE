class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> nodes(nums.begin(), nums.end());
        int count = 0;
        while (head) {
            if (nodes.count(head->val) && (!head->next || !nodes.count(head->next->val))) ++count;
            head = head->next;
        }
        return count;
    }
};