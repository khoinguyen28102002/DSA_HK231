#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int freshApples = 0;
    queue<pair<int, int>> rotten;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                rotten.push({i, j});
            } else if (grid[i][j] == 1) {
                freshApples++;
            }
        }
    }
    if (freshApples == 0) {
        return 0;
    }
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int sec = 0;
    while (!rotten.empty()) {
        int currentSize = rotten.size();
        for (int i = 0; i < currentSize; i++) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Mark the fresh apple as rotten
                    rotten.push({newX, newY});
                    freshApples--;
                }
            }
        }
        if (!rotten.empty()) {
            sec++;
        }
    }
    return (freshApples == 0) ? sec : -1;
}

int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
    return 0;
}