#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<string> mila(vector<vector<char> > &A, vector<string> &str);
};
Solution::Solution(){}
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool isValid(int x, int y, int row, int col)
{
    if(x < 0 || y < 0 || x >= row || y >= col)
    {
        return false;
    }
    return true;
}

bool bfs(vector<vector<char> > &A, int iter, int jter, string str)
{
    int k = 1;
    map<pair<int, int>, int > mp;
    mp[make_pair(iter, jter)]++;
    for(int i = 0; i < 8; i++)
    {
        int rd, cd;
        while(k < str.length())
        {
            rd = iter + dx[i];
            cd = jter + dy[i];
            if(mp.find(make_pair(rd, cd)) != mp.end())
            {
                break;
            }
            if(!isValid(rd,cd, A.size(), A[0].size()))
            {
                break;
            }
            if(A[rd][cd] != str[k])
            {
                break;
            }
            iter = rd;
            jter = cd;
            mp[make_pair(iter, jter)]++;
            k++;
            i = 0;
        }
    }
    if(k == str.length())
    {
        return true;
    }
    return false;
}
vector<string> Solution::mila(vector<vector<char> > &A, vector<string> &str)
{
    vector<string> res;
    for(vector<string>::iterator iter = str.begin(); iter != str.end(); iter++)
    {
        string cp = *iter;
        bool mila = false;
        for(int iter = 0; iter < A.size(); iter++)
        {
            for(int jter = 0; jter < A[iter].size(); jter++)
            {
                if(A[iter][jter] == cp[0])
                {
                    if(bfs(A, iter, jter, cp))
                    {
                        res.push_back(cp);
                        mila = true;
                        break;
                    }

                }
            }
            if(mila)
            {
                break;
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
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<string> str;
        for(int iter = 0; iter < n ;iter++)
        {
            string s;
            cin >> s;
            str.push_back(s);
        }

        int row, col;
        cin >> row >> col;
        vector<vector<char> > A;
        for(int iter = 0; iter < row; iter++)
        {
            vector<char> temp;
            for(int jter = 0; jter < col; jter++)
            {
                char ch;
                cin >> ch;
                temp.push_back(ch);
            }
            A.push_back(temp);
        }

        vector<string> ans = sol.mila(A, str);
        if(ans.size() == 0)
        {
            cout << -1;
        }
        else
        {
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());

            for(vector<string>::iterator iter = ans.begin(); iter != ans.end(); iter++)
            {
                cout << *iter << " ";
            }
        }
        cout << endl;

    }
    return 0;
}
