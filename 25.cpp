class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int x=k;
        ListNode* curr = head;
        while(k>0&&curr) {
            curr = curr->next;
            --k;
        }
        if(k>0) return head;
        curr = reverseKGroup(curr, x);
        while(x>0) {
            ListNode* nextHead = head->next;
            head->next = curr;
            curr = head;
            head=nextHead;
            --x;
        }
        return curr;
    }
};