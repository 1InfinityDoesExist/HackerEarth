#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string sortKar(pair<string, int> &p);
};
Solution::Solution(){}
string Solution::sortKar(pair<string, int> &p)
{
    string str = p.first;
    int n = p.second;
    if(n%2 == 0)
    {
        sort(str.begin(), str.end());
    }
    else
    {
        sort(str.begin(), str.end(), greater<char>());
    }
    string s = "";
    for(string::iterator iter = str.begin(); iter != str.end(); iter++)
    {
        if(isupper(*iter))
        {
            s += *iter;
        }
    }
    return s;
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
        pair<string, int> p;
        string str;
        cin >> str;
        int n;
        cin >> n;
        p = make_pair(str, n);
        string ans = sol.sortKar(p);
        if(ans.size() == 0)
        {
            cout << "NULL" <<endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
