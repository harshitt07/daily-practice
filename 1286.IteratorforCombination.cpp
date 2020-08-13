// Problem Link: https://leetcode.com/problems/iterator-for-combination/
// Approach: Brute Force - Bit Manupulation

class CombinationIterator {
public:
    
    // To store the length of the possible string
    // of given length K 
    set<string> Ans;
    
    // Used to find the next lexicographically
    // greater permutation of string prev 
    string prev = "";
    
    CombinationIterator(string characters, int combinationLength) {
        
        // String length
        int N = characters.length();
        
        // Till where we have to iterate to find
        // the string of length combinationLength
        // using bitmasking
        int mask = 1 << N;
        
        // Iterate till mask
        for(int i = 0; i < mask; i++) {
            
            // If current number i has number of
            // set bits as combinationLength
            // then find the possible string
            if(__builtin_popcount(i)==combinationLength) {
                
                string ans = "";
                
                // Append character at index of
                // set bit of number i
                
                // For example:
                // characters = "abcd", j = 
                // binary of 11 "1011"
                // Then resultant string is 
                // append character at index of
                // set bit i.e., "acd"(in this example)
                for(int j = 0; j < N; j++) {
                    
                    if(i&(1<<j)) {
                        ans = ans + characters[j];
                    }
                }
                
                // Insert the resultant string
                Ans.insert(ans);
            }
        }
    }
    
    string next() {
        
        // Find the upper bound of string
        auto it = Ans.upper_bound(prev);
        
        // If upperbound is not present
        // then return the empty string
        if(it==Ans.end()) {
            return "";
        }
        
        // Else Update the previous string
        // and return the string
        return prev = *it;
        
    }
    
    bool hasNext() {
        
        // If Upper bound doesn't exist
        // then return false
        return (Ans.upper_bound(prev)!=Ans.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */