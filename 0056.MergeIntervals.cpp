// Problem Link: https://leetcode.com/problems/merge-intervals/
// Approach: Sorting

#include "bits/stdc++.h"
#define lli long long int
#define fo(i, a, b) for(i = a; i < b; i++)
#define Fo(i, a, b) for(i = a; i > b-1; i--)
using namespace std;

class Solution {
public:
    
    // Comparator function for sorting
    bool static cmp(vector<int> &a, vector<int> &b) {
        if(a[0]==b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    // Function to check is any two intervals
    // overlaps or not
    bool isOverlap(vector<int> &a, vector<int> &b) {
        
        if((b[0] <= a[1])) {
            return true;
        }
        return false;
    }

    // Function to merge the given intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Base Case
        if(intervals.size()==0) return {};

        // Sort the given intervals
        sort(intervals.begin(), intervals.end(), cmp);
        
        int minElement = intervals[0][0];
        int maxElement = intervals[0][1];
        vector<vector<int> > Ans;
        
        // Traverse the intervals
        for(int i = 1; i < intervals.size(); i++) {
            
            vector<int> A = {minElement, maxElement};            
            
            // Check overlaps
            if(isOverlap(A, intervals[i])) {
                
                minElement = min(minElement, intervals[i][0]);
                maxElement = max(maxElement, intervals[i][1]);
            }
            
            // Insert the given pairs in the
            // resultant vector and update the
            // min and max Element
            else {
                Ans.push_back({minElement, maxElement});
                minElement = intervals[i][0];
                maxElement = intervals[i][1];
                // i++;
            }
        }
        
        // Insert the last pair of vectors
        Ans.push_back({minElement, maxElement});
        return Ans;
    }
};

// Function that prints all the intervals
void printResult(vector<vector<int>> &A) {
    
    for(auto &it : A) {
        for(auto &jt : it) {
            cout << jt << ' ';
        }
        cout << endl;
    }
    
}

// Driver Code
int main() {

    // Object of Class
    Solution *S = new Solution();

    vector<vector<int> > intervals = { {1, 3}, {2, 6},
                                       {8, 10}, {15, 18}};

    vector<vector<int> > Ans = S->merge(intervals);

    // Function Call
    printResult(Ans);
    return 0;
}
