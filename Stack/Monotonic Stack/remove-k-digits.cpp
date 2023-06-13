// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        // delete everything and return 0 in this case
        if(k >= n)return "0";
        // Make a monotonic stack, try for increasing order 
        // till the index possible. increasing seq->smallest number
        stack<char> stk; 
        stk.push(num[0]);
        int i = 1; 
        while(i < n){
	        // all conditions necessary. Keep on deleting until the 
	        // sequence becomes increasing
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            // push into the stack when found bigger digit
            stk.push(num[i]);
            i++;
        }
        // If more digits can be removed then remove the largest ones
        while(k--){
            stk.pop();
        }
        
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        // Remove zeroes in the front and handle corner cases
        int ind = -1; 
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] != '0'){
                ind = i; 
                break; 
            }
        }
        if(ind == -1)return "0";
        return ans.substr(ind, ans.size() - ind); 
    }
};
