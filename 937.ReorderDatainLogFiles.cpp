class Solution {
    
// Problem Link: https://leetcode.com/problems/reorder-data-in-log-files/
// Approach: STL 
public:
    
    static bool cmp(pair<string, string> &a, pair<string, string> &b) {
        if(a.first==b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<pair<string, string>> Ans;
        
        int i = 0;
        
        for(auto &it : logs) {            
            auto idx = it.find(' ');
            if(it[idx+1] >= 'a') {
                Ans.push_back({it.substr(idx, it.length()), it.substr(0, idx)});  
            }
            i++;
        }
        
        sort(Ans.begin(), Ans.end(), cmp);
        
        vector<string> A;
        for(auto &it : Ans) {
            A.push_back(it.second + it.first);
        }
        
        for(auto &it : logs) {
            if(it[it.length() - 1] >= '0' 
               && it[it.length() - 1] <= '9') {
                A.push_back(it);
            }
        }
        return A;
    }
};