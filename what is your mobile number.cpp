#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int validNumberOrNot(string str);
};
Solution::Solution(){}
int Solution::validNumberOrNot(string str)
{
    int len = str.length();
    if(len > 10 || len < 10)
    {
        return false;
    }
    str.erase(0, str.find_first_not_of('0'));
    if(len != str.length())
    {
        return false;
    }
    if(find(str.begin(), str.end(), '.') != str.end())
    {
        return false;
    }
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(!isdigit(str[iter]))
        {
            return false;
        }
    }
    return true;
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
        int ans = sol.validNumberOrNot(str);
        if(ans == 1)
        {
            cout << "YES"<<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }
    return 0;
}
