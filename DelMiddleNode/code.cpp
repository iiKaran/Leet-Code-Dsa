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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast, * slow , *prev; 
        fast = slow = head ; 
        prev= NULL ; 
        while( fast && fast->next)
        {
            prev = slow ;
            fast = fast->next->next ; 
            slow= slow->next ; 
        }
        if(prev && slow)
        {
            prev->next= slow->next ; 
        }
        if( prev==NULL)
        return NULL ; 
        
        return head ; 

    }
};