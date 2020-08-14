// Problem Link: https://leetcode.com/problems/longest-palindrome/
// Approach: Hashing and traversal of string
class Solution {
public:
    int longestPalindrome(string s) {
        
        int A[256] = {0};
        
        // Store frequency of each character
        for(char ch : s) {
            A[int(ch)]++;
        }
        
        // To count of frequencies which are odd
        int cnt = 0;
        for(int x : A) {
            if(x&1) cnt++;
        }
        
        // If there exists a odd number then
        // we can include only one odd number
        // of frequency to maximize the longest
        // palindromic length
        return (cnt==0 ? s.length() : s.length() - cnt + 1);
    }
};