class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int n, int curr, vector<int> &vis, stack<int> &s, vector<int> adj[]) 
	{
	    // code here
	    vis[curr]=1;
	    
	    for(auto neigh: adj[curr]) 
	    {
	        if(!vis[neigh]) dfs(n,neigh,vis,s,adj);
	    }
	    s.push(curr);
	}
	
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(n,0);
	    vector<int> res;
	    stack<int> s;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i]) dfs(n,i,vis,s,adj);
	    }
	    
	    while(s.size())
	    {
	        res.push_back(s.top());
	        s.pop();
	    }
	    
	    return res;
	}
};
