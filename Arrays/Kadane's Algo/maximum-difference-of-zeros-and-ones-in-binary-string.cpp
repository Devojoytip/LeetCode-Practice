// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// Kadane's Algo

class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int ans=-1e9, diff=0;
	    
	    for(int i=0;i<s.size();i++)
	    {
	        int j=(s[i]=='1') ? -1 : 1;
	        diff+=j;
	        ans=max(ans, diff);
	        if(diff<0) diff=0;
	    }
	    
	    return ans;
	}
};
