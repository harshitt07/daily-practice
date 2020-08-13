// Problem Link: https://leetcode.com/problems/majority-element-ii/
// Approach: Moore-Voting Algorithm, using track of two pointers
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size()==0) return {};
        
        // Initialise the current element
        // as the both the majority element
        int cnt1 = 0, cnt2 = 0;
        int a = nums[0];
        int b = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            
            // If current element is same as
            // a then increment the cnt1
            if(a==nums[i]) {
                cnt1++;
            }
            
            // If current element is same as
            // b then increment the cnt2
            else if(b==nums[i]) {
                cnt2++;
            }
            
            // If cnt1 is zero, then update
            // the first majority element
            // and increment it's count
            else if(cnt1==0) {
                a = nums[i];
                cnt1++;
            }
            
            // If cnt2 is zero, then update
            // the second majority element
            // and increment it's count 
            else if(cnt2==0) {
                b = nums[i];
                cnt2++;
            }
            
            // If current element is not
            // same as the first and second
            // majority element then
            // decrement both the count
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Initialise cnt1 and cnt2 to 0
        cnt1 = cnt2 = 0;
        
        // Since a and b can be our possible
        // majority element
        // Therefore find its count
        for(auto &it : nums) {
            
            if(it==a) {
                cnt1++;
            } else if(it==b) {
                cnt2++;
            }
            
        }
        
        vector<int> Ans;
        
        // If their count is N/3 then
        // insert it in the vector
        if(cnt1*3 > nums.size()) Ans.push_back(a);
        if(cnt2*3 > nums.size()) Ans.push_back(b);
        
        return Ans;
        
    }
};