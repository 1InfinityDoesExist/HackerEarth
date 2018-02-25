#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> subsetSum(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::subsetSum(vector<int> &A)
{
     vector<int> res;
     res.push_back(0);
    vector<vector<int> > subset;
    map<vector<int> , int> mp;
    subset.push_back(res);
    for(int iter = 0; iter < A.size(); iter++)
    {

        vector<vector<int> > cp = subset;
        for(int jter = 0; jter < cp.size(); jter++)
        {
            cp[jter].push_back(A[iter]);
        }
        for(int jter = 0; jter < cp.size(); jter++)
        {
            vector<int> temp = cp[jter];
            sort(temp.begin(), temp.end());
            subset.push_back(temp);
         //   if(mp.find(temp) == mp.end())
           // {
                mp[temp]++;
        //    }
        }
    }
    subset.clear();


    for(map<vector<int>, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        vector<int> temp = iter->first;
        int sum (0);
        for(int i = 0; i < temp.size(); i++)
        {
            sum = sum + temp[i];
        }
        int freq = iter->second;
        while(freq--)
        {
            res.push_back(sum);
        }
    }
    sort(res.begin(), res.end());
  //  res.erase(unique(res.begin(), res.end()), res.end());
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
        vector<int> ans = sol.subsetSum(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter <<" ";
        }
        cout << endl;
    }
    return 0;
}
