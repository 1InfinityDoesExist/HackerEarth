#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int totalCities(vector<pair<int, int> > &vp);
};
Solution::Solution(){}
int Solution::totalCities(vector<pair<int, int> > &vp)
{
    map<int, int> mp;
    for(vector<pair<int, int> >::iterator iter = vp.begin(); iter != vp.end(); iter++)
    {
        pair<int, int> p = *iter;
        mp[p.first]++;
        mp[p.second]++;
    }
    return mp.size();
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
        int n;
        cin >> n;
        vector<pair<int, int> > vp;
        for(int iter = 0; iter < n ;iter++)
        {
            int u, v;
            cin >> u >> v;
            vp.push_back(make_pair(u, v));
        }

        int ans = sol.totalCities(vp);
        cout << ans <<endl;
    }
}
