// Problem Link: https://leetcode.com/problems/target-sum/
// Approach: Dynamic Programming and Recursive Approach Commented

// Example: 1
// [1,2,7,9,981]
// 1000000000 
// Ans = 0

// Example: 2
// [0,0,1,1,0,1,0]
// 3
// Ans = 16

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    
    int countSumS(vector<int> &nums, int N, int S) {
       
        /*
        // Recursive Approach
        if(S==0 && N==0) return 1;
        if(N==0 && S!=0) return 0;
        
        if(nums[N-1] <= S) {
            return countSumS(nums, N - 1, S - nums[N-1]) 
                 + countSumS(nums, N - 1, S);
        }
        
        return countSumS(nums, N - 1, S);
        */
        
        // Dynamic Programming Approach
        
        // To store the count of zeros in the
        // given array
        int cntZero = 0;
        
        // DP table of N*S
        int dp[N+1][S+1];
        
        // value with sum 0 and N 0 is 1
        dp[0][0] = 1;
        
        
        for(int i = 1; i < N + 1; i++) {
            
            // If current element is zero
            // then we can 2*dp[i-1][0]
            // possible subsets
            
            // Example 2 where i got stucked
            if(nums[i - 1]==0) {
                dp[i][0] = 2*dp[i-1][0];
            }
            
            // Else we can get the count
            // of subset as the previous
            // cell value
            else dp[i][0] = dp[i-1][0];
        }
        
        // Initialise dp[0][i] as 0 because
        // count of subset with sum having
        // no element in the array is zero
        for(int i = 1; i < S + 1; i++) {
            dp[0][i] = 0;
        }
        
        // Update the dp table
        for(int i = 1; i < N + 1; i++) {
            
            for(int j = 1; j < S + 1; j++) {
                
                // Now if current sum is greater
                // than the current element then
                // we can this in the subset sum
                // count all the possible with
                // including and excluding the
                // current element
                
                // It simply means that the if
                // we can get a subset sum j with i
                // number of elements
                if(j >= nums[i-1]) {
                    
                                // Including            // Excluding
                    dp[i][j] = (dp[i-1][j - nums[i-1]] + dp[i-1][j]);
                }
                
                // Else Update as the previous
                // cell value
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
//         To print the DP Array
//         for(int i = 0; i < N + 1; i++) {
            
//             for(int j = 0; j < S + 1; j++) {
                
//                 cout << dp[i][j] << ' ';
//             }
//             cout << endl;
//         }
        
        // Return the total count
        return dp[N][S];
        
    }
    
    
    int findTargetSumWays(vector<int> &nums, int S) {
        
        int N = nums.size();
        long long int Sum = 0;
        
        // Find the sum of all the elements
        for(auto &it : nums) {
            Sum += it;
        }
        
        // Store the total Sum        
        int totalSum = Sum;
        
        if((Sum + S)&1) return 0;
        
        Sum = (1LL*Sum + S)/2;
        
        // If the sum needed exceeds the given
        // totalSum of the array then return 0
        
        // Example: 1 where i got runtime
        // error :(
        if(Sum > totalSum) return 0;
        
        // Function Call to find the count
        // of subset with the sum(Sum)
        return countSumS(nums, N, Sum);        
    }
};

// Driver Code
int main() {
    
    vector<int> arr = {0, 0, 1, 1, 0, 1, 0};
    
    int sum = 3;
    
    Solution *S = new Solution();
    
    cout << S->findTargetSumWays(arr, sum);
    
    return 0;
}