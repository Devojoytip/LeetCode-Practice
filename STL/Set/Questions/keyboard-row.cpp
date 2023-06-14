// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string> keyRows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        int row = 1;
        for (auto i: keyRows) {
            for (auto j: i) {
                mp[j] = row; // lowercase
                mp[toupper(j)] = row; // uppercase
            }
            row++;
        }

        vector<string> ans;
        unordered_set<int> us;
        for (auto i: words) {
            for (auto j: i) {
                us.insert(mp[j]);
            }

            if (us.size() == 1) ans.push_back(i);
            us.clear();
        }

        return ans;
    }
};
