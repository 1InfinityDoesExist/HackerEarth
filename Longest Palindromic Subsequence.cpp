#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LPS(string str);
};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::LPS(string str)
{
    int len = str.length();
    int dp[len][len];
    for(int iter = 0; iter < len ;iter++)
    {
        dp[iter][iter] = 1;
    }
    for(int kter = 2; kter <= len; kter++)
    {
        for(int iter = 0; iter < len-kter+1; iter++)
        {
            int jter = iter+kter-1;
            if(str[iter] == str[jter] && kter == 2)
            {
                dp[iter][jter] = 2;
            }
            else if(str[iter] == str[jter])
            {
                dp[iter][jter] = dp[iter+1][jter-1] + 2;
            }
            else
            {
                dp[iter][jter] = max(dp[iter][jter-1], dp[iter+1][jter]);
            }
        }
    }
    return dp[0][len-1];
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
        int ans = sol.LPS(str);
        cout << ans <<endl;
    }
    return 0;
}
