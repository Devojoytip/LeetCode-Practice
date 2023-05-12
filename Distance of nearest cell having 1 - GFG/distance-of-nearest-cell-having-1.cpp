//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:

    vector<vector<int>> nearest(vector<vector<int>> &v)
    {
        int m = v.size(), n = v[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 1 and !vis[i][j])
                {
                    dist[i][j] = 0;
                    v[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {

                int x1 = i + dx[k];
                int y1 = j + dy[k];
                if (x1 >= 0 and y1 >= 0 and x1 < v.size() and y1 < v[0].size() and !vis[x1][y1] and v[x1][y1] == 0)
                {
                    q.push({x1, y1});
                    if (v[x1][y1] == 1)
                        dist[x1][y1] = 0;
                    else
                        dist[x1][y1] = dist[i][j] + 1;
                    vis[x1][y1] = 1;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends