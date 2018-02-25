#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string shortURL(int n);
        int backtoNumber(string ans);
};
Solution::Solution(){}
string Solution::shortURL(int n)
{
    string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string str = "";
    while(n != 0)
    {
        str = s[n%62] + str;
        n /= 62;
    }
    return str;
}
int Solution::backtoNumber(string str)
{
    unsigned long long int ans = 0;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if('a' <= str[iter] && str[iter] <= 'z')
        {
            ans = ans*62 + str[iter] - 'a';
        }
        if('A' <= str[iter] && str[iter] <= 'Z')
        {
            ans = ans*62 + str[iter] - 'A' + 26;
        }
        if('0' <= str[iter] && str[iter] <= '9')
        {
            ans = ans*62 + str[iter] - '0' + 52;
        }
    }
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
        string ans = sol.shortURL(n);
        cout << ans << endl;
        int an = sol.backtoNumber(ans);
        cout << an << endl;
    }
    return 0;
}
