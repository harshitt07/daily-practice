// Problem Link: https://leetcode.com/problems/rotting-oranges/
// Approach: BFS using Queue 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        int cntOne = 0;
        int ans = 0;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        queue<pair<int, int> > Q;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j]==2) {
                    Q.push({i, j});
                } else if(grid[i][j]==1) {
                    cntOne++;
                }
            }
        }
        
        // cout << Q.size(); 
        
        while(!Q.empty()) {
            
            if(cntOne==0) {
                break;
            }
            
            ans++;
            int currSize =  Q.size();
            
            // cout << ans << ' ' << currSize << '\n';
            
            while(currSize--) {
                
                pair<int, int> temp = Q.front();
                Q.pop();
                
                for(int i = 0; i < 4; i++) {
                    
                    int x = temp.first + dx[i];
                    int y = temp.second + dy[i];
                    
                    if(x < 0 || y < 0 || x >= N || y >= M) continue;
                    
                    if(grid[x][y]==1) {
                        cntOne--;
                        Q.push({x, y});
                        grid[x][y] = 2;
                    } 
                    
                }
            }
        }
        
        return (cntOne==0 ? ans : -1);
    }
};