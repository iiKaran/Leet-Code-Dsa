class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> last ; 
        map<char, bool> vis ;
        stack<char> stk ; 
        for( int i =0; i < s.length();i++)
        {
            last[s[i]]= i ; 
            vis[s[i]] = false ; 
        }         
        for( int i =0; i <s.length();i++){
            int index = i ; 
            char curr= s[i];
          if(vis[curr]) continue ; 
           while( !stk.empty() && stk.top()>curr && last[stk.top()]> index)
            {

               vis[stk.top()]= false ;
               stk.pop(); 
            }
            stk.push(curr); 
            vis[curr]= true ; 
        }
          
          string res = ""; 
          while(!stk.empty())
          {
              res += stk.top(); 
              stk.pop(); 
          }
          reverse(res.begin(), res.end());
          return res ;
    }
};
