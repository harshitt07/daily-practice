// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Two Pointers and Hashing of characters
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        
        // To store the frequency of
        // all characters
        int freq[256] = {0};
        
        int i, ans = 0;
        int minIndex = 0;
        
        // Traverse the string
        for(i = 0; s[i]; i++) {
            
            // Increment the current
            // character frequency
            freq[int(s[i])]++;
            
            // If frequency of current
            // character > 1
            if(freq[int(s[i])] > 1) {
                
                // Update the maximum length
                ans = max(ans, i - minIndex);
                
                // Traverse string from minIndex
                // and keep decrementing the 
                // frequency of character until
                // frequency of current character
                // is 1 
                while(freq[int(s[i])] > 1) {
                    freq[int(s[minIndex])]--;
                    minIndex++;
                }
            }
        }
        
        // Update the maximum again for
        // minIndex to last pointer
        ans = max(ans, i - minIndex);
        
        // Return the maximum length
        return ans;
    }
};