// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution {
public:
    class myCmp{

        public:

        bool operator()(const string &s1, const string &s2)
        {
            if(s1.length()>s2.length()) return 1;
            
            else if(s1.length()<s2.length()) return 0;
                
            else
            {
                for(int i=0;i<s1.length();i++)
                {
                    if(s1[i]-'0'>s2[i]-'0') return 1;

                    else if(s1[i]-'0'<s2[i]-'0') return 0;
                }

                return 0;
            }
            
        }
    };

    string kthLargestNumber(vector<string>& v, int k) {
        //idea is to create an min heap
        priority_queue<string,vector<string>,myCmp> pq;
        
        for(int i=0;i<v.size();i++)
        {
            pq.push(v[i]);
            if(pq.size()>k) pq.pop();                       
        }
        
        return pq.top();
        
    }
};
