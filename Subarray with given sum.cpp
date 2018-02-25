#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<int, int> Subarray_with_given_sum(vector<int> &A, const int sum);
};
Solution::Solution(){}
bool comp(pair<int, int> &A, pair<int, int> &B)
{
    return A.first < B.first;
}
pair<int, int> Solution::Subarray_with_given_sum(vector<int> &A, const int sum)
{
    int n = A.size();
    vector<pair<int, int> > all;
    int maxlength (1);
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] == sum)
        {
            all.push_back(make_pair(iter+1, iter+1));
        }
    }

    int start (0);
    int end (0);
    for(int iter = 0; iter < A.size()-1 ;iter++)
    {
        if(A[iter] + A[iter+1] == sum)
        {
            start = iter+1;
            end = iter+2;
            maxlength = 2;
            all.push_back(make_pair(start, end));
        }
    }
    for(int kter = 3; kter <= A.size(); kter++)
    {
        for(int iter = 0; iter < n-kter+1; iter++)
        {
            int jter = iter+kter-1;
            int sm (0);
            for(int pter = iter ; pter <= jter ; pter++)
            {
                sm = sm + A[pter];
            }
            if(sm == sum)
            {
                if(maxlength < kter)
                {
                    maxlength = kter;
                    start = iter+1;
                    end = jter+1;
                    all.push_back(make_pair(start, end));
                }
            }
        }
    }
    sort(all.begin(), all.end(), comp);
    if(all.size() == 0)
    {
        return make_pair(-1, 0);
    }
    else
    {
        return all[0];
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
        int n;
        cin >> n;
        int sum;
        cin >> sum;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        pair<int, int> range = sol.Subarray_with_given_sum(A, sum);
        if(range.second == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << range.first << " " <<range.second <<endl;
        }
    }
    return 0;
}
