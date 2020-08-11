// Problem: https://leetcode.com/problems/partition-labels/ 
// Approach: Iterative, Two Pointers
    
class Solution {
public:
    
    // Function to find the labels
    vector<int> partitionLabels(string S) {
        
        int A[26] = {0};
        
        // This loop is used to store the last
        // index of each character in S
        for(int i = 0; S[i]; i++) {
            A[S[i] - 'a'] = i;
        }
        
        // To store the label
        vector<int> Ans;
        
        // To store the count of labels
        int label = 0;
        
        // To store the maxIndex
        int maxIndex  = 0;
        
        // Traverse the string
        for(int i = 0; S[i]; i++) {
            
            // Update the maxIndex
            maxIndex = max(maxIndex, A[S[i] - 'a']);
            
            // If same then insert this length
            // in vector Ans and update the
            // label and maxIndex
            if(i==maxIndex) {
                Ans.push_back(i - label + 1);
                label = i + 1;
            }
            
        }
        
        // Return the ans
        return Ans;        
    }
};