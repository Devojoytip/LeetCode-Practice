/*

Dutch national flag algo

Time: O(N)
Space: O(1)

0 - low -> all 0s
low - mid -> all 1s
mid - high -> all 2s

*/

class Solution {
public:
    void sortColors(vector<int>& v) {

        int low=0,mid=0,high=v.size()-1;

        while(mid<=high)
        {
            if(v[mid]==0)
            {
                swap(v[mid],v[low]);
                low++;
                mid++;
            }
            else if(v[mid]==2)
            {
                swap(v[mid],v[high]);
                high--;
            }
            else mid++;            
        }
    }
};
