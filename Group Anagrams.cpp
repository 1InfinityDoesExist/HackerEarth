class Solution {

public:


   /*  bool comp(vector<string> &A, vector<string> &B)
    {
        return A.size() < B.size();
    }
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string , vector<string> > mp;

        for(vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++)
        {
            string st = *iter;
            sort(st.begin(), st.end());
            mp[st].push_back(*iter);
        }

        for(map<string, vector<string> >::iterator iter = mp.begin(); iter != mp.end(); iter++)
        {
            vector<string> cp = iter->second;
            sort(cp.begin(), cp.end());
            res.push_back(cp);
        }
        sort(res.begin(), res.end(),[](vector<string> &A, vector<string> &B){ return A.size() < B.size(); });
        return res;


    }
};
