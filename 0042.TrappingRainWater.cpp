// Problem Link: https://leetcode.com/problems/trapping-rain-water/
// Approach: Two-Pointer, MinMax Approach

#include "bits/stdc++.h"
#define lli long long int
#define fo(i, a, b) for(i = a; i < b; i++)
#define Fo(i, a, b) for(i = a; i > b-1; i--)
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        // If no element then return 0
        int N = height.size();
        if(N==0) return 0;
        
        vector<int> left(N, 0), right(N, 0);
        left[0] = height[0];
        right[N-1] = height[N-1];
        
        // Update the left the max array
        for(int i = 1; i < N; i++) {
            left[i] = max(height[i], left[i-1]);
        }
        
        // Update the right the max array
        for(int i = N - 2; i >= 0; i--) {
            right[i] = max(height[i], right[i+1]);
        }
        
        int trap = 0;

        // Update the trap water using minimum
        // of the maximum at current index
        // minus height of the current index
        for(int i = 0; i < N; i++) {
            trap += (min(left[i], right[i]) - height[i]);
        }

        // Return the trapped water amount
        return trap;
    }
};

// Driver Code
int main() {

    // Object of Class
    Solution *S = new Solution();

    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Function Call
    cout << S->trap(arr);

    return 0;
}
