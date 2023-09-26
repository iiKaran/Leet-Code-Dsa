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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int,int> mp ; 
        for( auto i : nums)
        mp[i]++; 

        int res = nums.size(); 
        while(head->next !=NULL)
        {
            if(mp[head->val] && mp[head->next->val])
            res--; 
            
            head= head->next ; 
        }
        return res ;
    }
};