#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int vowel(string str);
};
Solution::Solution(){}
int Solution::vowel(string str)
{
    map<char, int> mp;
    mp['a'] = 1;
    mp['e'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;

    map<char, int> m;
    for(string::iterator iter = str.begin(); iter != str.end(); iter++)
    {
        if(mp.find(*iter) != mp.end())
        {
            m[*iter]++;
        }
    }
    if(m.size() == 5)
    {
        return true;
    }
    return false;

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
        int ans = sol.vowel(str);
        if(ans == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
