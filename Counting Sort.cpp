#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<pair<int, int> > countSort(vector<int> &A);
};
Solution::Solution(){}
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}
vector<pair<int, int> > Solution::countSort(vector<int> &A)
{
    map<int, int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    vector<pair<int, int> > vp ;
    for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        vp.push_back(make_pair(iter->first, iter->second));
    }
    sort(vp.begin(), vp.end(), comp);
    return vp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<int> A;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        A.push_back(data);
    }
    vector<pair<int, int > > ans = sol.countSort(A);
    for(vector<pair<int, int>>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        pair<int, int> p = *iter;
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
