// 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution
{
private:
    vector<vector<bool>> visited;
public:
    void traverse_grid(vector<vector<char>> &grid, int n, int m, int i, int j){
        int row, col, r, c;
        stack<pair<int, int>> stck;
        visited[i][j] = true;
        stck.push(make_pair(i, j));
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (stck.size()){
            pair<int, int> top = stck.top(); stck.pop();
            row = top.first; col = top.second;
            for (auto it : moves) {
                r = row + it.first; c = col + it.second;
                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == '1' && visited[r][c] == false) {
                    stck.push(make_pair(r, c));
                    visited[r][c] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int num_of_island = 0;
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    num_of_island++;
                    traverse_grid(grid, n, m, i, j);
                }
            }
        }
        return num_of_island;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '1'}};
    int num = sol.numIslands(grid);
    cout << num << endl;
}