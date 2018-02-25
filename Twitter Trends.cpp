#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<string> sortingWala(string str);
};
Solution::Solution(){}
bool comp(pair<string, int > &A, pair<string, int> &B)
{
    if(A.second == B.second)
    {
        return A.first < B.first;
    }
    return A.second > B.second;
}
vector<string> Solution::sortingWala(string str)
{
   // cout << str << endl;
    vector<string> res;
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == ' ')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                if(s[0] == '#')
                {
                    res.push_back(s);
                }
                s = "";
            }
        }
        else
        {
            s = s+ str[iter];
            if(iter == str.length()-1)
            {
                if(s[0] == '#')
                {
                    res.push_back(s);
                }
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<string> vs;
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        string str;
        getline(cin, str);

        vector<string> dalo = sol.sortingWala(str);
        for(vector<string>::iterator iter = dalo.begin(); iter != dalo.end(); iter++)
        {
            vs.push_back(*iter);
        }
        dalo.clear();
    }
    map<string, int> mp;
    for(vector<string>::iterator iter = vs.begin(); iter != vs.end(); iter++)
    {
        mp[*iter]++;
    }
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    vector<pair<string , int> > v;
    for(int iter = 0; iter < vs.size(); iter++)
    {
      //  cout << vs[iter] << " --->" <<mp[vs[iter]] << endl;
        v.push_back(make_pair(vs[iter], mp[vs[iter]]));
    }
    sort(v.begin(), v.end(), comp);
    int count (0);
    for(vector<pair<string, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        count++;
        pair<string, int> p = *iter;
        cout << p.first <<endl;
        if(count == 5)
        {
            break;
        }
    }
    cout << endl;
    return 0;
}
