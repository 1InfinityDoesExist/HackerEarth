#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    public:
        Solution();
        void solvequery(map<int , string> &mp, const int query);
};
Solution::Solution(){}
void Solution::solvequery(map<int , string> &mp, const int query)
{
    for(int iter = 0; iter < query; iter++)
    {
        int data;
        cin >> data;
        cout << mp[data] << endl;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    map<int, string> mp;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        string str;
        cin >> str;
        mp[data] = str;
    }
    int query;
    cin >> query;
    sol.solvequery(mp, query);
    return 0;
}
