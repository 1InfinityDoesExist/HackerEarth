#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> emirpNumber(int n);
};
Solution::Solution(){}
bool isValidNotPalindrome(int iter)
{
    string str = to_string(iter);
    int start = 0;
    int end = str.length()-1;
    while(start < end)
    {
        if(str[start++] != str[end--])
        {
            return false;
        }
    }
    return true;
}
vector<int> Solution::emirpNumber(int n)
{
    map<int, int> res;
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int iter = 2; iter <= n; iter++)
    {
        if(dp[iter] == 0)
        {
           if( iter >= 13  && !isValidNotPalindrome(iter) )
           {
               res[iter]++;
           }
            for(int jter = 2*iter; jter <= n; jter = jter+iter)
            {
                dp[jter] = 1;
            }
        }
    }

    vector<int> ans;
    for(map<int, int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        int cp = iter->first;
        int rev_num (0);
        while(cp > 0)
        {
            rev_num = rev_num*10 + cp%10;
            cp /= 10;
        }
        if(res.find(rev_num) != res.end() )
        {
            ans.push_back(iter->first);
        }
    }
    res.clear();
    return ans;
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
        vector<int> ans = sol.emirpNumber(n);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
