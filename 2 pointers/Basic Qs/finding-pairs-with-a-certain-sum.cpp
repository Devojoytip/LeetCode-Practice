// https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
public:
    vector<int> v1,v2;
    unordered_map<int,int> mp;

    FindSumPairs(vector<int>& v1, vector<int>& v2) {
        this->v1=v1; 
        this->v2=v2;
        for(auto it:v2) mp[it]++; 
    }
    
    void add(int i, int val) {
        if(i>=v2.size())
        {
            v2.push_back(val);
            mp[val]++;
            return;
        }
        mp[v2[i]]--;
        v2[i]+=val;
        mp[v2[i]]++;
    }
    
    int count(int tot) {

        int ans=0;
        for(auto it:v1)
        {
            int rem=tot-it;
            ans+=mp[rem];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
