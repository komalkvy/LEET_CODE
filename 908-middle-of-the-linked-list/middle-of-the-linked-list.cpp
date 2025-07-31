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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        int cnt = 0;
        ListNode*temp =head;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int step = 0;
        while(temp!=nullptr){
            if(step==cnt/2)return temp;
            step++;
            temp = temp->next;
        }
        return nullptr;
    }
};