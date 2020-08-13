// Problem Link: https://leetcode.com/problems/majority-element/
// Approach: Single-Traversal, using Moore-Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Initialise the first element as
        // the majority element
        int major = nums[0];
        
        // Frequency of the majority element
        // is 1(currently)
        int frequency = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            
            // Increase the frequency if
            // current element is current
            // majority element
            // Else decrement it
            frequency += (nums[i]==major) ? 1 : -1;
            
            // If frequency is zero, then
            // update the majority element
            if(frequency==0) {
                major = nums[i + 1];
            }
        }
        
        return major;
    }
};