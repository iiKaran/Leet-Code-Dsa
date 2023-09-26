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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode * temp = list1 ;
            for( int i =0; i < a-1 ; i++)
            {
                temp = temp->next ;
            }
            // now at the start ; 
            ListNode*start = temp ; 

            for( int i =0; i <= b-a && temp  ;i++)
            {
                temp = temp->next ; 
            }

            ListNode * end = NULL ; 
            
            if(temp)
            end = temp->next ; 

            start->next = list2 ; 

            ListNode * last2 = list2 ; 
            
            while( last2->next )
            {
                last2= last2->next ;
            }
            last2->next = end ; 
            
    
    return list1; 
    }
};