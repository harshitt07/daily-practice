// Problem Link: https://leetcode.com/problems/ugly-number-iii/
// Approach: Binary Search

class Solution {
public:
    
    // To find the LCM
    long long int lcm(long long int a, long long int b) {
        
        int  gcd = __gcd(a, b);
        
        long long int x = a*b;
        
        return x/gcd;
        
    }
    
    // To check if mid is the Nth Ugly number or
    // not by count how many numbers are there
    // till mid that are multiple of a, b, c
    int checkMid(int mid, int a, int b, int c) {
        
        return (mid/a +  mid/b + mid/c
              - mid/lcm(a, b) - mid/lcm(c, b)
              - mid/lcm(a, c) + mid/lcm(a, lcm(b, c)));        
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        
        if(a==1 || b==1 || c==1) {
            return n;
        }
        
        // Answer lies in the range [1, 2*10^9]
        int low = 1, high = 2000000000;
        
        // Perform Binary Search
        while(low < high) {
            
            int mid = low + (high - low)/2;
            
            // Check mid
            if(checkMid(mid, a, b, c) >= n) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
            
        }
        
        // Return the number
        return high;
    }
};