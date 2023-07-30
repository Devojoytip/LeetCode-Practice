class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> in_deg(n,0);
	    vector<int> res;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(auto neigh: adj[i]) in_deg[neigh]++;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(in_deg[i]==0) s.push(i);
	    }
	    
	    while(s.size())
	    {
	        int curr=s.top();
	        s.pop();
	        res.push_back(curr);
	        
	        for(auto neigh: adj[curr])
	        {
	            if(in_deg[neigh]>0) in_deg[neigh]--;
	            if(in_deg[neigh]==0) s.push(neigh);
	        }
	    }
	    
	    return res;
	}
};
