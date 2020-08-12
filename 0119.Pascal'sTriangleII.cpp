// Problem Link: https://leetcode.com/problems/pascals-triangle-ii/
// Approach: Mathematical - Combinatorics
class Solution {
public:
    
    // Function to find NcR
    int findnCr(int N, int R) {
        
        if(R==0 || N==R) return 1;
        
        long long int ans = 1;
        
        // Find NcR by dividing (N--/i++)
        for(int i = 1; i <= R; i++) {
            ans *= N;
            ans /= i;
            N--;
        }
        return ans;
    }
    
    vector<int> getRow(int rowIndex) {
        
        vector<int> Ans;
        
        // Traverse till [0, rowIndex] and
        // find the value of nCr
        for(int i = 0; i < rowIndex + 1; i++) {
            
            // Append the value of nCr
            Ans.push_back(findnCr(rowIndex, i));
        }
        
        return Ans;
    }
};