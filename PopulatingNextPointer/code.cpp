
class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>>q ; 

        if(root==NULL)
        {
            return root ; 
        }
        if(root->left==NULL)
        {
            root->next = NULL; 
            return root ; 
        }
        int lv = 0 ; 
        q.push({root,lv}); 
        
        Node* temp = NULL ; 

        while(!q.empty())
        {
           
        
            for( int i =0; i <q.size();i++)
            {
                Node * top = q.front().first; 
              
          
                int lv = q.front().second ;
                  q.pop(); 
               if(q.empty())
               {
                   top->next = NULL ; 
               }
               else{
                   
                   if(q.front().second == lv)
                   top->next = q.front().first;
               }
                if(top->left)
                q.push({top->left, lv+1});
                if(top->right)
                q.push({top->right, lv+1}); 

                
            }
            lv++;
        }

        return root;
    }
};