#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int repeatedKTimes(vector<int> &A, int k);
};
Solution::Solution(){}
int Solution::repeatedKTimes(vector<int> &A, int k)
{
    vector<int> ans;
    map<int, int> mp;
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        mp[*iter]++;
    }
    for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second == k)
        {
            ans.push_back(iter->first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[0];

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
    int k;
    cin >> k;
    int ans = sol.repeatedKTimes(A, k);
    cout << ans <<endl;
}
