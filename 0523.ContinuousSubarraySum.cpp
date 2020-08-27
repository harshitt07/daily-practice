// Problem Link: https://leetcode.com/problems/continuous-subarray-sum/
// Approach: Hashing
// Variation of Subarray with given Sum K,
// Variation Link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // To store the given sum%k
        unordered_map<int, int> M;
        
        // If k is zero, then make it to avoid
        // modulo to 0
        if(k==0) k = INT_MAX;
        
        // To handle the cases [0, 0] 
        M[0] = -1;
        int sum = 0;
        
        // Iterate the given array nums
        for(int i = 0; i < nums.size(); i++) {
            
            // Find sum
            sum += nums[i];
            
            // Modulo it to k
            sum %= k;
            
            // If value exists the check for
            // difference of the index is 
            // 1 or not
            if(M.find(sum)!=M.end()) {
                
                // Return true if valid
                // subarray of size
                // at least 2
                if(i - M[sum] > 1) {
                    return true;
                }
            }
            
            // Update the first occurrence of
            // the index of the sum
            else M[sum] = i;
        }
        
        // Return false if nothing found
        return false;
    }
};