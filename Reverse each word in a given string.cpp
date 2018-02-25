#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string reverseEachWord(string str);
};
Solution::Solution(){}
string Solution::reverseEachWord(string str)
{
    queue<string> q;
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == '.')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                reverse(s.begin(), s.end());
                q.push(s);
                s = "";
            }
        }
        else
        {
            s = s+str[iter];
            if(iter == str.length()-1)
            {
                reverse(s.begin(), s.end());
                q.push(s);
                break;
            }
        }
    }

    str = "";
    while(!q.empty())
    {
        if(q.size() == 1)
        {
            str = str + q.front();
            return str;
        }
        string st = q.front();
        q.pop();
        str = str + st;
        str = str + '.';
    }
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
        string ans = sol.reverseEachWord(str);
        cout << ans << endl;
    }
    return 0;
}
