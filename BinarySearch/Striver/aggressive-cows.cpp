// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

bool check(vector<int> &v, int k, int mini)
{
    int lastCow=v[0], cows=1;

    for(int i=1;i<v.size();i++)
    {
        if(v[i] - lastCow >= mini)
        {
            cows++;
            lastCow=v[i];
        }

        if(cows>=k) return 1;
    }

    return 0;
}

int aggressiveCows(vector<int> &v, int k)
{
    //    Write your code here.
    sort(v.begin(),v.end());

    int s=1, e=v.back()-v[0];

    while(s<=e)
    {
        int mid=(s+e)/2;

        bool flag=check(v,k,mid);

        if(flag) s=mid+1;

        else e=mid-1;
    }

    return e;
}
