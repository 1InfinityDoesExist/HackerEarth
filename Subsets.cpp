#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
         vector<vector<int> > subset(vector<int> &A);
};
Solution::Solution(){}
vector<vector<int> > Solution::subset(vector<int> &set)
{

    vector< vector<int> > subset;
    map<vector<int> , int> mp;
    vector<vector<int> > res;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > cp = subset;

        for (int j = 0; j < cp.size(); j++)
        {
            cp[j].push_back( set[i] );
        }


        for (int j = 0; j < cp.size(); j++)
        {
            vector<int> dup = cp[j];
            sort(dup.begin(), dup.end());
            subset.push_back( dup );
            if(mp.find(dup) == mp.end())
            {
                mp[dup]++;
            }
        }
    }
    for(map<vector<int>, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        res.push_back(iter->first);
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
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<vector<int> > ans = sol.subset(A);
       cout << "()";
        for(int iter = 0; iter < ans.size(); iter++)
        {
            cout <<'(';
            for(int jter = 0; jter < ans[iter].size(); jter++)
            {
                if(jter == ans[iter].size()-1)
                {
                    cout << ans[iter][jter] << "";
                }
                else
                {
                    cout << ans[iter][jter] << " ";
                }
            }
            cout << ')' << "";
        }
        cout << endl;
    }
    return 0;
}
