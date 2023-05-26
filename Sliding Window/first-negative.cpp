// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) 
{
    long long int i=0,j=0,neg=0;
    vector<long long> v;
    queue<long long> q;
    
    while(j<n)
    {
        while(j-i+1<k)
        {
            if(a[j]<0) q.push(a[j]);
            j++;
        }
        
        if(j-i+1==k)
        {
            
            if(j<n and a[j]<0) q.push(a[j]); // since in 1st while loop when we reach the window size we break out and dont push v[j]
            
            if(!q.empty())
            {
                v.push_back(q.front());
            }
            else v.push_back(0);
            
            if(!q.empty() and q.front()==a[i]) q.pop();
            
            i++; // not to push v[i] as its already included with v[j]
            j++;

        }
    }
    
    return v;
}
