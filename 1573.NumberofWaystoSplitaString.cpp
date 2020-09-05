// Problem Link: https://leetcode.com/problems/number-of-ways-to-split-a-string/
// Approach: Binary Search with prefix sum but accurracy is only 12%
// will update it to single traversal of strings
class Solution {
public:
    int numWays(string s) {
        
        // Count the number of 1s
        int countOne = count(s.begin(), s.end(), '1');
        
        // If not possible
        if(countOne%3!=0) return 0;
        
        int N = s.length();
        
        if(countOne==0) {
            return ((1LL*(N -1)*(N - 2))%1000000007)/2;
        
        }
        
        // Total number of 1s in each substring
        countOne /= 3;
        
        vector<int> A(N);
        if(s[0]=='1') A[0] = 1;
        else A[0] = 0;
        
        // Prefix sum array A[]
        for(int i = 1; s[i]; i++) {
            A[i] = A[i - 1] + (s[i]=='1');
        }
        
        //  string S = 1010001010011
        // Array A[] = 1 1 2 2 2 2 3 3 4 4 4 5 6 
        
        int a = lower_bound(A.begin(), A.end(), countOne) - A.begin();
        int b = lower_bound(A.begin(), A.end(), countOne + 1) - A.begin();
        int d = lower_bound(A.begin(), A.end(), 2*countOne) - A.begin();
        int c = lower_bound(A.begin(), A.end(), 2*countOne + 1) - A.begin();
        
        // cout << a << ' ' << b << ' ' << c << endl;
        
        // Find the count of zeros between 
        // the two subarrays
        int zero1 = b - a, zero2 = c - d;
        
        // Return modulo to 10^9 + 7
        return (1LL*zero1*zero2)%1000000007;
    }
};