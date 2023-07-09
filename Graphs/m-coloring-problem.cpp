// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
public:

    bool check(int n, int curr, int m, bool graph[101][101], int color[], int col) 
    {
        // your code here
        
        // check all its neighbours
        for(int i=0;i<n;i++)
        {
            if(graph[i][curr] and i!=curr and color[i]==col) return 0;
            
            if(graph[curr][i] and i!=curr and color[i]==col) return 0;
        }
        
        return 1;
    }
    
    bool sol(int n, int curr, int m, bool graph[101][101], int color[])
    {
        if(curr==n) return 1;
        
        for(int col=1;col<=m;col++) // try all colors
        {
            if(check(n,curr,m,graph,color,col)) 
            {
                color[curr]=col;   
                if(sol(n,curr+1,m,graph,color)) return 1;
                
                // back-track
                color[curr]=0;
            }
        }
        
        return 0;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        int color[n]={0};
        return sol(n,0,m,graph,color);
    }
};
