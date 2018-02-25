/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this function*/
bool is_k_palin(string s,int k)
{
//Your code here
    string p = s;
    reverse(p.begin(), p.end());
    int m = s.length();
    int n = p.length();

    int dp[m+1][n+1];
    for(int iter = 0; iter <= m; iter++)
    {
        for(int jter = 0; jter <= n; jter++)
        {
            if(iter == 0 || jter == 0)
            {
                dp[iter][jter] = 0;
            }
            else if(s[iter-1] == p[jter-1])
            {
                dp[iter][jter] = dp[iter-1][jter-1] +1;
            }
            else
            {
                dp[iter][jter] = max(dp[iter-1][jter], dp[iter][jter-1]);
            }
        }
    }
    return (m - dp[m][n] <= k);
}
