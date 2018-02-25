#include<bits/stdc++.h>
using namespace std;

bool dp[1000001];
class Solution
{
    private:
    public:
        Solution();
        int primeSumOrNot(int n);
};
Solution::Solution(){}
void primeCalc()
{

    memset(dp, true, sizeof(dp));
    dp[0] = dp[1] = false;
    for(int iter = 2; iter <= 1000001; iter++)
    {
        if(dp[iter] == true)
        {
            for(int jter = 2*iter; jter <= 1000001; jter = jter+iter)
            {
                dp[jter] = false;
            }
        }
    }
}
int Solution::primeSumOrNot(int n)
{
   for(int iter = 2; iter < n ;iter++)
   {
       if(dp[iter] == true && dp[n-iter] == true)
       {
           return true;
       }
   }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    primeCalc();
    while(testCase--)
    {
        int n;
        cin >> n;

        int ans = sol.primeSumOrNot(n);
        if(ans == 1)
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
