// https://leetcode.com/problems/prison-cells-after-n-days

/*

Pattern : After n = 14, the pattern repeats
thus n%=14;

*/

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n)
    {
        if(n == 0) return cells;

        else
        {
            if(n>14) n %= 14;
            if(n==0) n = 14;
            vector<int> arr;
            arr = cells;
            
            while(n--)
            {
                for(int i = 1; i < cells.size()-1; i++)
                {
                    if(arr[i-1] == arr[i+1]) cells[i] = 1;
                    else cells[i] = 0;
                }
                cells[0] = cells[cells.size()-1] = 0;
                arr = cells;
            }
            return cells;
        }
    }
};
