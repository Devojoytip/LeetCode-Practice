// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {

        int n=q.size(), ans=-1;

        if(n==0) return ans;

        while(n!=1)
        {
            ans=q.front();
            q.pop();
            q.push(ans);
            n--;
        }

        ans=q.front();
        q.pop();
        return ans;
        
    }
    
    int top() 
    {
        int n=q.size(), ans=-1;

        if(n==0) return ans;

        while(n>0)
        {
            ans=q.front();
            q.pop();
            q.push(ans);
            n--;
        }

        return ans;
    }
    
    bool empty() 
    {
        return q.empty();
    }
};
