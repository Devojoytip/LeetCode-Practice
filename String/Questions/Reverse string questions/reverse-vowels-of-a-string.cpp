// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        
        int i = 0, j = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        while (i < j) 
        {
            while (i < j and !isVowel(s[i], vowels)) i++;
            while (i < j and !isVowel(s[j], vowels)) j--;
            swap(s[i++], s[j--]);
        }

        return s;
    }

private:
    bool isVowel(char& ch, unordered_set<char>& vowels) 
    {
        return vowels.find(tolower(ch)) != vowels.end();
    }
};
