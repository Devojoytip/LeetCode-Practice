/*

https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

Step 1. Use 2 pointers, one fast and the other slow until fast reaches the end. Put the numbers into the stack while traversing slow pointer.

Step 2. Move slow pointer further, and pop the stack

*/

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast=head, *slow=fast;
        stack<int> st;
        while(fast){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int ans=0;
        while(slow){
            int x=st.top();
            st.pop();
            ans=max(ans, x+(slow->val));
            slow=slow->next;
        }
        return ans;
    }
};
