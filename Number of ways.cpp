#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        unsigned long long int tilingProcess(unsigned long long int n);
};
Solution::Solution(){}
unsigned long long int Solution::tilingProcess(unsigned long long int n)
{
    unsigned long long int dp[n+1];
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for(int iter = 4; iter <= n; iter++)
    {
        dp[iter] = dp[iter-1] + dp[iter-4];
    }
    return dp[n];
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
        unsigned long long int n;
        cin >> n;
        unsigned long long int ans = sol.tilingProcess(n);
        cout << ans << endl;
    }
    return 0;
}
