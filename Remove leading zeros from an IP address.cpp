#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string removeLeadingZeros(string str);
};
Solution::Solution(){}
string Solution::removeLeadingZeros(string str)
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
                s.erase(0, s.find_first_not_of('0'));
                q.push(s);
                s = "";
            }
        }
        else
        {
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                s.erase(0, s.find_first_not_of('0'));
                q.push(s);
            }
        }
    }
    str = "";
    while(!q.empty())
    {
        if(q.size() == 1)
        {
            str += q.front();
            return str;
        }
        if(q.front() == "")
        {
            str += '0';
            str += '.';
            q.pop();
        }
        else
        {
            str += q.front();
            str += '.';
            q.pop();
        }
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
        string ans = sol.removeLeadingZeros(str);
        cout << ans <<endl;
    }
    return 0;
}
