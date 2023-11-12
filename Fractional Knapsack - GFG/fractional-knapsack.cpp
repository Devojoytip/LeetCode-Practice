//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item a[], int n)
    {
        // Your code here
        
        double prof=0;
        
        vector<pair<double, int>> v;
        
        for(int i=0;i<n;i++) v.push_back({(double)a[i].value/a[i].weight, a[i].weight});
        
        sort(v.begin(), v.end(), [](const pair<double, int> &a, const pair<double, int> &b)
        {
            if(a.first==b.first) return a.second>b.second;
            
            return a.first>b.first;
        });
        
        for(int i=0;i<n;i++)
        {
            if(w==0) break;
            int take=min(v[i].second, w);
            w-=take;
            prof+=(double)take*v[i].first;
        }
        
        return prof;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends