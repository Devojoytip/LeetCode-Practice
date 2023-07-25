// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        
        stack<int> s1;
        stack<int> s2;
        list<int> l;

        while(h1) 
        {
            s1.push(h1->val);
            h1=h1->next;
        }

        while(h2) 
        {
            s2.push(h2->val);
            h2=h2->next;
        }

        int carry=0;

        while(s1.size() or s2.size())
        {
            int sum=carry;
            
            if(s1.size()) 
            {
                sum+=s1.top();
                s1.pop();
            }

            if(s2.size()) 
            {
                sum+=s2.top();
                s2.pop();
            }
            
            carry=sum/10;
            sum%=10;
            l.push_front(sum);
        }

        if(carry) l.push_front(carry);

        ListNode* h=new ListNode(0);
        ListNode* t=h;

        while(l.size())
        {
            t->next=new ListNode(l.front());
            t=t->next;
            l.pop_front();
        }

        return h->next;
    }
};
