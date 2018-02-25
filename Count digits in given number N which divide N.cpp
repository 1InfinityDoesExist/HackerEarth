#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int divisibl(string n);
};
Solution::Solution(){}
bool divi(string str, int n)
{
    int ans = 0;
    for(int iter = 0; iter < str.length(); iter++)
    {
        ans = (ans*10 + (str[iter] - '0'));
        ans = ans%n;
    }
    return ans == 0;
}
int Solution::divisibl(string n)
{
    bool dp[10];
    memset(dp, false, sizeof(dp));
    dp[1] = true;
    for(int digit = 2; digit <= 9; digit++)
    {
        if(divi(n, digit))
        {
            dp[digit] = true;
        }
    }
    int result (0);
    for(int iter = 0; iter < n.length(); iter++)
    {
        if(dp[n[iter] -'0'])
        {
            result++;
        }
    }
    return result;
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
        string n;
        cin >> n;
        int ans = sol.divisibl(n);
        cout << ans << endl;
    }
    return 0;
}
