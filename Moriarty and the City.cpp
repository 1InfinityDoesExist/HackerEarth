#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        unsigned long long int ghar(vector<int> &A);
};
Solution::Solution(){}
unsigned long long int max(unsigned long long int x, unsigned long long int y)
{
    return x > y ? x : y;
}
unsigned long long int Solution::ghar(vector<int > &A)
{

    vector<int> cp = A;
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    if(cp.size() == 1)
    {
        return A.size();
    }
     int mx (0);
    unsigned long long int count (0);
    bool mila = false;
    for(int iter = 1; iter < A.size(); iter++)
    {
        if(A[iter] == A[iter-1])
        {
            mila = true;
            count++;
            if(iter == A.size()-1)
            {
                if(mila)
                {
                    count += 1;
                    mx = max(mx, count);
                    return mx;
                }
            }
            continue;
        }
        if(mila)
        {
            count = count+1;
            mila = false;
            mx = max(mx, count);
            count = 0;
        }
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    unsigned long long int n;
    cin >> n;
    vector<int> A;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        A.push_back(data);
    }
    unsigned long long int ans = sol.ghar(A);
    cout << ans << endl;
    return 0;
}
