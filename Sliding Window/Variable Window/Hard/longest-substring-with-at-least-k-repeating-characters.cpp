/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0)
           return 0;
        
        int arr[26] = {0};
        for(auto i : s){
            arr[i - 'a']++;
        }
        
        bool flag = true;
        for(int i = 0 ; i < 26 ; i++){
            if(arr[i] > 0 && arr[i] < k){
                flag = false;
                break;
            }
        }
        if(flag) return s.size();
        
        int i = 0 , start = 0 , ans = 0;
        while(i < s.size()){
            if(arr[s[i] - 'a'] < k ){
                ans = max(ans,longestSubstring(s.substr(start,i - start),k));
                start++;
            }
            i++;
        }
        
        ans = max(ans,longestSubstring(s.substr(start),k));
        
        return ans;
    }
};
