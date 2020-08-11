// Problem Link: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Approach: Hashing
class Solution {
public:
    
    // Function to compare two strings on
    // the basis of order in A[]
    bool compareString(string S, string T, int A[]) {
        
        int i = 0;
        
        // Traverse till each
        // character are same
        while(S[i]==T[i]) {
            i++;
        }
        
        // If reach at the end of S, then
        // return true
        if(i==S.length()) return true;
        if(i==T.length()) return false;
        
        // Return true or false
        return A[S[i] - 'a'] < A[T[i] - 'a'];
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        int A[26];
        
        // Hash every character with
        // index in string order
        for(int i = 0; order[i]; i++) {
            A[order[i] - 'a'] = i;
        }
        
        // Traverse the array of strings
        for(int i = 0; i < words.size() - 1; i++) {
            
            // Compare Adjacent Characters
            // If it is false then words[]
            // is not in sorted order 
            if(!compareString(words[i], words[i + 1], A)) {
                return false;
            }
            
        }
        
        // Sorted Order
        return true;
    }
};