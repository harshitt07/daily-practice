// Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/ 
// Approach: LL Traversal with map to store index of each node
// Time Complexity: O(3*N)
// Auxiliary Space: O(2*N)

// Follow Up: will come up without using map solution :)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // Base Case
        if(!head) return head;
        
        // Store the head in curr
        Node *curr = head;
        
        // Stores the Node with its occurrence
        // of it's index
        unordered_map<Node*, int> M;
        
        // To Store the resultant node of LL
        vector<Node*> A;
        int i = 0;
        
        // Traverse the LL
        while(curr) {
            
            // Insert the current Node with
            // it's occurrence of index
            M.insert({curr, i});
            
            // Make the newNode with curr
            // node value into A
            A.push_back(new Node(curr->val));
            
            // Increment i and move curr
            curr = curr->next;
            i++;
        }
        
        i = 1;
        
        // Now Linked the next pointer of
        // every prev node A[i - 1] to the
        // next node A[i]
        for( ; i < (int)A.size(); i++) {
            A[i - 1]->next = A[i];
        }
        
        // Point curr to head
        curr = head;
        i = 0;
        
        // Traverse the given LL
        while(curr) {
            
            // Now check the index of the
            // current node's random
            
            // Map the corresponding current
            // node in A[] and map it to the
            // index of random
            if(curr->random) A[i]->random = A[M[curr->random]];
            
            // If Null then mark it as NULL
            else A[i]->random = NULL;
            
            // Increment i and move curr
            curr = curr->next;
            i++;
        }
        
        // Now A[0] will have the resultant LL
        return A[0];
    }
};