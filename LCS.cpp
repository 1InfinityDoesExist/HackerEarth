#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LCS(string &str1, string &str2);
};
Solution::Solution(){}
int Solution::LCS(string &str1, string &str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int dp[len1+1][len2+1];
    for(int iter = 0; iter <= len1; iter++)
    {
        for(int jter = 0; jter <= len2; jter++)
        {
            if(iter == 0 || jter == 0)
            {
                dp[iter][jter] = 0;
            }
            else if(str1[iter-1] == str2[jter-1])
            {
                dp[iter][jter] = 1 + dp[iter-1][jter-1];
            }
            else
            {
                dp[iter][jter] = max(dp[iter-1][jter] , dp[iter][jter-1]);
            }
        }
    }
    return dp[len1][len2];
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
        int m;
        cin >> m;
        int n;
        cin >> n;
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        int ans = sol.LCS(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
