// Problem Link: https://leetcode.com/problems/palindrome-linked-list/
// Approach: Traversal of LL, first half reverse then second half will
//           traverse forward than first half backward checks palindromic
// Time Complexity: O(N)
// Auxiliary Space: O(1) (Follow Up) :)
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
// 1 2 3 4 5 6
// 1 2 3 4 5
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        
        // Base Case
        if(head==NULL || head->next==NULL) return true;
        
        // Stores the length of the LL
        int l = 0;
        ListNode *curr = head;
        
        // Traverse LL
        while(curr) {
            l++;
            curr = curr->next;
        }
        
        // Stores the previous and curr node
        ListNode *prev = NULL;
        ListNode *currNext;
        
        curr = head;
        
        // Traverse the half and reverse it
        for(int i = 0; i < l/2; i++) {
            
            // Step 1: Store the next pointer
            // in currNext
            currNext = curr->next;
            
            // Step 2: Assign next pointer to
            // the prev node
            curr->next = prev;
            
            // Step 3: Update prev to curr
            prev = curr;
            
            // Got error in this line,
            // previously curr = curr->next
            
            // Step 4: Set the curr node to
            // next node in original LL i.e.,
            // currNext
            curr = currNext;
        }
        
        // If it is of odd length then no need to
        // check this node as it is middle node
        if(l&1) currNext = currNext->next;
        
        // Example 1:
        /*
        previous LL:         1->2->3->4->5->NULL
        new LL:        NULL<-1<-2  3->4->5->NULL
        */
        
        // Example 2:
        /*
        previous LL:         1->2->3->4->5->6->NULL
        new LL:        NULL<-1<-2<-3  4->5->6->NULL
        */
        
        // Traverse the prev in backward
        // and currNext in forward
        while(prev && currNext) {
            
            // If any mismatch then return false
            if(prev->val!=currNext->val) return false;
            
            // Move backward
            prev = prev->next;
            
            // Move forward
            currNext = currNext->next;
        }
        
        // It means LL is palindromic
        return true;
    }
};

// To fast the algorithm
static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(nullptr);
static ostream* _far = cout.tie(nullptr);