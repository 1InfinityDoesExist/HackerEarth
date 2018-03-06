#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int beerAndString(vector<string> &A, string str);
};
Solution::Solution(){}
int Solution::beerAndString(vector<string> &A, string str)
{
    int count (0);
    map<char, int> mp;
    for(string::iterator iter = str.begin(); iter != str.end(); iter++)
    {
        mp[*iter]++;
    }
    for(vector<string>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        string ss = *iter;
        map<char, int> m;
        for(string::size_type jter = 0; jter < ss.size(); jter++)
        {
            m[ss[jter]]++;
        }
        bool mila = true;
        for(map<char, int>::iterator jter = m.begin(); jter != m.end(); jter++)
        {
            if(mp.find(jter->first) == mp.end())// || m[jter->first] != mp[jter->first])
            {
                mila = false;
                break;
            }
        }
        if(mila)
        {
            count++;
        }
        m.clear();
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    string str;
    cin >> str;
    int testCase;
    cin >> testCase;
    vector<string> A;
    while(testCase--)
    {
        string s;
        cin >> s;
        A.push_back(s);
    }
    int ans = sol.beerAndString(A, str);
    cout << ans <<endl;
    return 0;
}
