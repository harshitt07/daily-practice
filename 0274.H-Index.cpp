// Problem Link: https://leetcode.com/problems/h-index/
// Approach: Hashing

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int N = citations.size();
        
        int freq[N + 1];
        
        memset(freq, 0, sizeof(freq));
        
        // Create frequency array of
        // the elements in citations
        for(int x : citations) {
            freq[min(N, x)]++;
        }
        
        // To store the sum of frequency
        // from reverse order in freq[]
        int sum = 0;
        
        for(int i = N; i > 0; i--) {
            
            sum += freq[i];
            
            // Return that index if at
            // any index sum >= index
            if(i <= sum) {
                return i;
            }
        }
        
        // Return 0 for element [0]
        return 0;       
    }
};