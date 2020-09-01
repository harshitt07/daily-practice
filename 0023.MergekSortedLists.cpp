// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Approach1: Merge Sort Approach with merge two sorted linked lists
// Approach2: Traverse the list and merge two sorted linked lists consecutively

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // Recursively program to merge two linked list
    // L1 and L2
    ListNode* mergeTwoSortedList(ListNode *L1, ListNode *L2) {
        
        // Base Case
        if(!L1) return L2;
        if(!L2) return L1;
        
        // L1 values is less than L2 then
        // recursive merge LL L2 and L1->next
        if(L1->val <= L2->val) {
            L1->next = mergeTwoSortedList(L2, L1->next);
            return L1;
        }
        
        // L2 values is less than L1 then
        // recursive merge LL L1 and L2->next
        L2->next = mergeTwoSortedList(L1, L2->next);
        return L2;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Base Case
        if(lists.size()==0) return NULL;
        
        int N = lists.size();
        
        // Until N is greater than 1
        while(N > 1) {

            for(int i = 0; i < N/2; i++) {
                
                // Merge 1st and last list
                // Merge 2nd and 2nd last
                // and so on...
                lists[i] = mergeTwoSortedList(lists[i],
                                              lists[N - i - 1]);
            }
            
            // Update the value of N as after
            // merging list becomes half
            N = (N + 1)/2;
        }
        
        // Return the final list
        return lists[0];        
        
        /*
        Iterative Approach
        
        // Traverse the list and merge two list
        // consecutively and return the final list
        // formed at last index
        for(int i = 0; i < (int)lists.size() - 1; i++) {
        
            lists[i + 1] = mergeTwoSortedList(lists[i],
                                              lists[i + 1]);
        }
        
        // Return the Final List
        return lists[(int)lists.size() - 1];
        */
    }
};