#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int hightesUniqueElement(map<int, int> &A);
};
Solution::Solution(){}
bool comp(pair<int, int> &A, pair<int, int> &B)
{
    if(A.second == B.second)
    {
        return A.first > B.first;
    }
    return A.second < B.second;
}
int Solution::hightesUniqueElement(map<int, int> &A)
{
    vector<pair<int, int> > vp;
    for(map<int, int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        vp.push_back(make_pair(iter->first, iter->second));
    }
    sort(vp.begin(), vp.end(), comp);
    pair<int, int> p = vp[0];
    if(p.second == 1)
    {
        return p.first;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    map<int, int> mp;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        mp[data]++;
    }
    int ans = sol.hightesUniqueElement(mp);
    cout << ans << endl;
    return 0;
}
