// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* h) {
        
        vector<int> v;
        while(h) 
        {
            v.push_back(h->val);
            h=h->next;
        }

        stack<int> st;
        st.push(0);

        for(int i=v.size()-1;i>=0;i--)
        {
            int curr=v[i];
            while(st.top()!=0 and st.top()<=curr) st.pop();
            v[i]=st.top();
            st.push(curr);
        }

        return v;
    }
};
