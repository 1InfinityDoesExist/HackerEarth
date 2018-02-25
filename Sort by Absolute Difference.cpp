#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> absoluteDiffSorting(vector<int> &A, int k);
};
Solution::Solution(){}
bool comp(pair<int, int> &A, pair<int, int> &B)
{
    if(A.second == B.second)
    {
        return A.first < B.first;
    }
    return A.second < B.second;
}
vector<int> Solution::absoluteDiffSorting(vector<int> &A, int k)
{
    vector<int> ans;
    vector<pair<int, int> > vp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        vp.push_back(make_pair(iter, abs(k-A[iter])));
    }
    sort(vp.begin(), vp.end(), comp);
    for(vector<pair<int, int> >::iterator iter = vp.begin(); iter != vp.end(); iter++)
    {
        pair<int, int> p = *iter;
        ans.push_back(A[p.first]);
    }
    return ans;
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
        int kth;
        cin >> kth;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.absoluteDiffSorting(A, kth);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
