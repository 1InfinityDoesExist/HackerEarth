#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<pair<char, int> > easyString(string str);
};
Solution::Solution(){}
vector<pair<char, int> > Solution::easyString(string str)
{
    vector<pair<char, int> > vp;
    map<char, int> mp;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(isupper(str[iter]))
        {
            str[iter] = tolower(str[iter]);
        }
        if(mp.size() == 0)
        {
            mp[str[iter]]++;
            continue;
        }
        if(mp.find(str[iter]) == mp.end())
        {
            vp.push_back(make_pair(str[iter-1], mp[str[iter-1]]));
            mp.clear();
            mp[str[iter]]++;
        }
        else
        {
            mp[str[iter]]++;
        }
    }
    map<char, int>::iterator iter = mp.begin();
    vp.push_back(make_pair(iter->first, iter->second));
    return vp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        string str;
        cin >> str;
        vector<pair<char, int> > ans = sol.easyString(str);
        for(vector<pair<char, int> >::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            pair<char, int> p = *iter;
            cout << iter ->second<< iter->first;
        }
        cout << endl;
    }
    return 0;
}
