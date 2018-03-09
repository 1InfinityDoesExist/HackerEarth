#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int treeOrNot(vector<int> &A);
};
Solution::Solution(){}
int Solution::treeOrNot(vector<int> &A)
{
    unsigned long long int edges = A.size();
    unsigned long long int sum (0);
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        sum += *iter;
    }
    if(sum == 2*(edges-1))
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
    int n;
    cin >> n;
    vector<int> A;
    for(int iter = 0; iter < n ;iter++)
    {
        int data;
        cin >> data;
        A.push_back(data);
    }
    int ans = sol.treeOrNot(A);
    if(ans == 1)
    {
        cout << "Yes" <<endl;
    }
    else
    {
        cout <<  "No" <<endl;
    }
    return 0;
}
