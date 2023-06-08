// https://leetcode.com/problems/reorder-list

class Solution {
public:
    void reorderList(ListNode* head) {
        //find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }
        //divide list in two parts
        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = NULL;

        //put second part of list into the stack
        stack<ListNode*> stack;
        ListNode* temp = list2;
        while(temp){
            stack.push(temp);
            temp = temp->next;
        }

        //now pop from stack and insert node into list1
        temp = list1;
        while(temp != NULL && !stack.empty()){
            ListNode* nextNode = temp->next;
            ListNode* newNext = stack.top();
            stack.pop();
            temp->next = newNext;
            newNext->next = nextNode;
            temp = temp->next->next; 
        }
    }
};
