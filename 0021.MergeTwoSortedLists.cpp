// Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Approach: Iterative Approach and Recursive Approach in comments

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // Base Case
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        /*
        Recursive Approach
         
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l2, l1->next);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }      
        */
        
        // dummy node to store the head of the
        // new linked list and curr node to
        // store the end of the new linked list
        ListNode *dummy, *curr;
        
        // If value of l1 is <= l2
        // point dummy to l1
        if(l1->val <= l2->val) {
            dummy = l1;
            l1 = l1->next;
        }
        
        // Else point dummy to l2
        else {
            dummy = l2;
            l2 = l2->next;
        }
        
        // Point curr to dummy the current
        // end of the linked list
        curr = dummy;
        
        // Till l1 and l2 reaches empty
        while(l1 && l2) {
            
            // If value of l1 is <= l2
            // point curr->next to l1
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            
            // Else point curr->next to l2
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            
            // Update the curr to curr->next
            curr = curr->next;
                
        }
        
        // This steps means any one of the
        // l1 or l2 reaches NULL
        
        // Update curr->next to corresponding
        // l1 and l2 pointer
        if(l1==NULL) {
            curr->next = l2;
        } else {
            curr->next = l1;
        }
        
        // Return the dummy node
        return dummy;
    }
};