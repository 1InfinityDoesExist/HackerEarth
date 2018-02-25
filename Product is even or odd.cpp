#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int productIsEvenOrOdd(string x, string y);
};
Solution::Solution(){}
int Solution::productIsEvenOrOdd(string x, string y)
{
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int a = x[0] - '0';
    int b = y[0] - '0';
    if((a*b)%2 == 0)
    {
        return 1;
    }
    return 0;

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
        string x;
         cin >> x;
         string y;
         cin >> y;
         int ans = sol.productIsEvenOrOdd(x, y);
         cout << ans <<endl;
    }
    return 0;
}
