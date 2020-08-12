// Problem Link: https://www.spoj.com/problems/TOPOSORT/
// Approach: BFS using priority_queue
// Problem Tag: Topological Sort

// C++ program for topological sort
#include <bits/stdc++.h>
using namespace std;

// Function to implement topologicalSort
void topologicalSort(vector<int> Adj[], 
                     vector<int> &inDegree, int N) {
    
    // Initialise the priority-queue to get
    // topological sort in lexicographical
    // order if it exists
    priority_queue<int, vector<int>, greater<int>> Q;

    // To store the topological sort
    vector<int> result;

    // Step 1:
    // Insert all nodes with inDegree 0
    // in the queue Q
    for(int i = 1; i <= N; i++) {

        if(inDegree[i]==0) Q.push(i);
    }

    // Step 2:
    // Traverse the queue and remove all
    // the edges connected to each node
    // stored in queue.

    // After removing the edges, for any
    // edge say u-->v if inDegree[v] is 0
    // after removing this edge then
    // insert node v in the queue for
    // topological sort

    // Insert each node in queue Q
    // in result to get the topological
    // sorting of graph
    while(!Q.empty()) {

        // Get the node in Q
        int src = Q.top();

        // Insert the current node
        // in result
        result.push_back(src);

        // Pop the node
        Q.pop();

        // Traverse the Adjacency list of src
        for(auto &child : Adj[src]) {

            // Decrement the inDegree
            inDegree[child]--;

            // If any child node whose
            // inDegree is 0, then insert
            // it in queue Q
            if(inDegree[child]==0) {
                Q.push(child);
            }
        }        
    }

    if(result.size()==N) {
        
        // Print the result
        for(auto &it : result) {
            cout << it << ' ';
        }
    }
    else {
        cout << "Sandro fails.";
    }
}

// Driver Code
int main() {
    
    // Number of Nodes
    int N; cin >> N;

    // Number of Edges
    int E; cin >> E;

    // Adjacency List
    vector<int> Adj[N + 1];

    // To store the indegree of
    // the node
    vector<int> inDegree(N+1, 0);

    // Input Edges
    while(E--) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        inDegree[v]++;
    }

    // Function Call for topological
    // sorting
    topologicalSort(Adj, inDegree, N);
    return 0;
}

// Input:
// 9
// 10
// 1 2
// 1 8
// 2 5
// 2 9
// 3 4
// 4 5
// 4 8
// 5 7
// 5 9
// 6 7

// Output:
// 1 2 3 4 5 6 7 8 9

// Input:
// 8
// 9
// 1 4
// 1 2
// 4 2
// 4 3
// 3 2
// 5 2
// 3 5
// 8 2
// 8 6
// Output:
// 1 4 3 5 7 8 2 6 
