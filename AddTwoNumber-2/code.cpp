
class Solution {
public:
 ListNode* reverse(ListNode* head) {
    if (!head || !head->next)
      return head;

    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverse( l1); 
        l2 = reverse( l2 ); 
          ListNode * ans = new ListNode(); 
        ListNode * temp = ans ;
        int c = 0 ;
        
        while( l1!= NULL || l2 != NULL || c )
        {
            int sum = 0 ; 
            if(l1 != NULL)
            {
                sum  = sum + l1->val ;
                l1 = l1->next ; 
            }
            if (l2 != NULL)
            {
                sum  = sum + l2->val ;
                l2 = l2->next ;           
            }
            sum += c ; 
            c = sum / 10 ; 
            
           
        ListNode  * node = new ListNode( sum % 10); 
        temp->next = node ; 
        temp = temp -> next ; 
        }
        while(l1 != NULL)
        {
            int sum =  c+ l1->val ;
            l1 = l1->next ; 
            c = sum / 10 ; 
        ListNode  * node = new ListNode( sum % 10); 
        temp->next = node ; 
        temp = temp -> next ; 
        }
        while(l2 != NULL)
        {
            int sum =  c+ l2->val ;
            l2 = l2->next ; 
            c = sum / 10 ; 
        ListNode  * node = new ListNode( sum % 10); 
        temp->next = node ; 
        temp = temp -> next ; 
        }
    
    if(c!= 0)
    {
        ListNode  * node = new ListNode(c); 
        temp->next = node ; 
        temp = temp -> next ; 
    }

        return reverse(ans->next);
    
    }
    
};