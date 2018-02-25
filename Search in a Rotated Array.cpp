#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int Search_in_a_Rotated_Array(vector<int> &A, const int val);
};
Solution::Solution(){}
int Solution::Search_in_a_Rotated_Array(vector<int> &A, const int target)
{
    int low = 0;
    int high = A.size()-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(A[mid] == target)
        {
            return mid;
        }
        if(A[low] <= A[mid])
        {
            if(target >= A[low] && target < A[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
        }
        else
        {
            if(target > A[mid] && target <= A[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return A[low] == target ? 1 : -1;
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
        int val;
        cin >> val;
        int ans = sol.Search_in_a_Rotated_Array(A, val);
        cout  << ans <<endl;
    }
    return 0;
}
