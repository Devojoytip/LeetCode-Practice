// https://leetcode.com/problems/validate-ip-address

class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        // At very first we check the string queryIP is IPv4 or IPv6 type ipaddress according to that we proceed further
        bool isdot;    // if ture means IPv4 type else IPv6 type
        int count = 0; // check the length of string between two consecutve dots because we want to use stoi() builtin function if length is extra than expected we directly return Neither
        for (auto x : queryIP)
        {
            if (x == '.')
            {
                isdot = true;
                if (count > 4)
                    return "Neither"; // we know 0<=x>=255 means string length between two dots must be less than 3 so we choose any number greater or equal to 3
                count = 0;
            }
            if (x == ':')
            {
                isdot = false;
                break;
            }
            count++;
        }
        // this section is for check correct IPv4 IP address
        if (isdot)
        {
            int count = 0;
            string st = "";
            for (int i = 0; i < queryIP.length(); i++)
            {
                if (queryIP[i] == '.')
                {
                    if (st.length() == 0)
                        return "Neither";
                    int s = stoi(st);
                    if (s < 0 or s > 255)
                        return "Neither";
                    string str = to_string(s);
                    if (st != str) // to check leading 0s condition
                        return "Neither";
                    st = "";
                    count++;
                }
                else if (queryIP[i] >= 48 and queryIP[i] < 58)
                    st += queryIP[i];
                else
                    return "Neither";
            }
            // this is only for the block which is after the last dot
            if (st.length() == 0)
                return "Neither";
            int s = stoi(st);
            if (s < 0 or s > 255)
                return "Neither";
            string str = to_string(s);
            if (st != str)
                return "Neither";
            return count == 3 ? "IPv4" : "Neither"; // this condition check given address must be in proper format x.x.x.x
        }

        // this section is for check correct IPv6 IPaddress
        int length = 0;
        count = 0;
        for (int i = 0; i < queryIP.length(); i++)
        {
            if (queryIP[i] == ':')
            {
                if (length == 0 or length > 4)
                    return "Neither";
                length = 0;
                count++;
            }
            else if (queryIP[i] >= 97 and queryIP[i] <= 102)
                length++;
            else if (queryIP[i] >= 65 and queryIP[i] <= 70)
                length++;
            else if (queryIP[i] >= 48 and queryIP[i] < 58)
                length++;
            else
            {
                cout << queryIP[i] << endl;
                return "Neither";
            }
        }
        if (length == 0 or length > 4)
            return "Neither";
        return count == 7 ? "IPv6" : "Neither"; // this condition is for check the given address must be in proper format x:x:x:x:x:x:x:x
    }
};
