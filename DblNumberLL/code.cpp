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
    ListNode* reverse(ListNode* head){
        ListNode * prev , *next , *curr ; 
        
        if(head && head->next ==NULL)
        return head ; 
         
        prev = NULL ; 
        curr = head ; 
        next = head->next ; 


        while(curr)
        {
              next = curr->next; 
              curr->next = prev ; 
              prev = curr ; 
              curr = next ; 
        }
        return prev ; 
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode * reversed = reverse(head); 

        
        // add the curr ll two time 
        int carry = 0 ; 


        ListNode * curr = reversed ; 
        ListNode * tempNode = new ListNode(-1);
        ListNode * ans = tempNode; 
        while( curr)
        {
               int sum = carry + curr->val+ curr->val ; 
               
               if(sum<=9)
               {
                   carry = 0 ; 
                   tempNode->next = new ListNode(sum); 
                   tempNode= tempNode->next ; 
               }
               else{
                   tempNode->next = new ListNode(sum%10); 
                   tempNode = tempNode->next ; 
                   carry= sum/ 10 ;
               }
               curr = curr->next ; 
        }
        if(carry != 0)
        {
                 tempNode->next = new ListNode(carry); 
                   tempNode= tempNode->next ;  
        }
        return reverse(ans->next) ;
    }
};