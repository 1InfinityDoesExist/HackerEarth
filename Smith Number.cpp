#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int smithNumber(int n);
};
Solution::Solution(){}
int summationDigit(int n)
{
    int summation (0);
    while(n != 0)
    {
        int rem = n%10;
        summation += rem;
        n /= 10;
    }
    return summation;
}
int Solution::smithNumber(int n)
{
    int cp = n;

    int summation = summationDigit(n);
    vector<int> res;
    while(cp%2 == 0)
    {
        res.push_back(2);
        cp /= 2;
    }
    for(int iter = 3; iter <= sqrt(cp); iter = iter+2)
    {
        while(cp%iter == 0)
        {
            res.push_back(iter);
            cp /= iter;
        }
    }
    if(cp > 2)
    {
        res.push_back(cp);
    }
    int sum (0);
    if(res.size() == 1)
    {
        return 0;
    }
    for(int iter = 0; iter < res.size(); iter++)
    {
       // cout << res[iter] << " ";
        sum = sum + summationDigit(res[iter]);
    }

    if(sum == summation)
    {
        return 1;
    }
    return  0;
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
        int ans = sol.smithNumber(n);
        cout << ans << endl;
    }
    return 0;
}
