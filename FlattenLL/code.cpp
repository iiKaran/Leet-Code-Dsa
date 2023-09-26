/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * curr = head ; 
        while(curr)
        {
            Node * next = curr->next; 
            
               if(curr->child)
               {
                   Node * child = curr->child ; 
                   Node * last = child ; 

                   while( last->next ) 
                   last = last->next ; 

                  

                   child->prev = curr ;
                   curr->next = child ; 
                   last->next = next ; 

                   if(next)
                   next->prev = last ; 
                   
                   curr->child=nullptr; 
                 
               }
                 curr = curr->next ; 
        }
        return head; 
    }
};