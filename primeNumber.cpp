#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    void prime(int n);
};
Solution::Solution(){}
void Solution::prime(int n)
{
    vector<int> ans;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int iter = 50; iter <= n; iter++)
    {
        if(dp[iter] == 0)
        {
            ans.push_back(iter);
            for(int jter = 2*iter; jter <= n; jter= jter+iter)
            {
                dp[jter] = 1;
            }
        }
    }
    for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
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
        sol.prime(n);
    }
    return 0;
}
