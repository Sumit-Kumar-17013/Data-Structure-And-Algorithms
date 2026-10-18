/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // tc : O(n)
        set<ListNode*> s;
        ListNode* curr = head;

        while(curr != NULL)
        {
            if(s.count(curr))
            {
                return true;
            }
            s.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};