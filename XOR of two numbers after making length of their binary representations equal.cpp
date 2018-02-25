#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int padding(int n, int m);
};
Solution::Solution(){}
int Solution::padding(int n, int m)
{
    string str1 = "";
    while(n != 0)
    {
        str1 = ((n%2 == 0) ? "0" : "1") + str1;
        n /= 2;
    }
    string str2 = "";
    while(m != 0)
    {
        str2 = ((m%2 == 0) ? "0" : "1") + str2;
        m /= 2;
    }
    int len = max(str1.length(), str2.length());
    if(str1.length() < len)
    {
        str1 = str1 + string(len-str1.length(),'0');
    }
    if(str2.length() < len)
    {
        str2 = str2 + string(len-str2.length(), '0');
    }
    int x = bitset<64>(str1).to_ulong();
    int y = bitset<64>(str2).to_ulong();
    return (x | y) & (~x | ~y);
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
        int m;
        cin >> m;
        int ans = sol.padding(n, m);
        cout << ans <<endl;
    }
    return 0;
}
