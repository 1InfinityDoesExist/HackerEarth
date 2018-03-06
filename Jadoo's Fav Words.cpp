#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string solve(vector<string> &A, string str);
};
Solution::Solution(){}
string Solution::solve(vector<string> &A, string str)
{
    queue<string> q;
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if((str[iter] == ' ' || str[iter] == '.' || str[iter] == ',') && iter != str.length()-1)
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                if(find(A.begin(), A.end(), s) != A.end())
                {
                    for(string::size_type jter = 0; jter < s.length(); jter++)
                    {
                        s[jter] = toupper(s[jter]);
                    }
                }
                if(str[iter] == '.')
                {
                    s = s + '.';
                    q.push(s);
                    s = "";
                    continue;
                }
                if(str[iter] == ',')
                {
                    s = s + ',';
                    q.push(s);
                    s = "";
                    continue;
                }
                q.push(s);
                s = "";
            }
        }

        else
        {

            if(iter == str.length()-1)
            {
                if(find(A.begin(), A.end(), s) != A.end())
                {
                    for(string::size_type jter = 0; jter < s.length(); jter++)
                    {
                        s[jter] = toupper(s[jter]);
                    }
                }
            }
             s = s + str[iter];
             if(iter == str.length()-1)
             {
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
        str += q.front();
        str = str + " ";
        q.pop();
    }
    return str;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<string> vs;
    for(int iter = 0; iter < n; iter++)
    {
        string str;
        cin >> str;
        vs.push_back(str);
    }
    int m;
    cin >> m;
    cin.ignore();
    string str;
    getline(cin, str);
    string ans = sol.solve(vs, str);
    cout << ans <<endl;
    return 0;
}
