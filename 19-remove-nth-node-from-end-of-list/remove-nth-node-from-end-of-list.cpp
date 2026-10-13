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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // tc = O(n)
        int len = 0;
        ListNode* curr = head;

        while(curr != NULL) // Length Calculate
        {
            curr = curr->next;
            len++;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int jump = len - n;

        ListNode* prev = dummy;

        while(jump > 0)
        {
            prev = prev->next;
            jump--;
        }
        prev->next = prev->next->next;

        return dummy->next;
        
    }
};