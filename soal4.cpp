#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, int fr, int fc, int R, int C,
         const vector<vector<int>> &grid, vector<vector<bool>> &visited,
         int &pathCount) {

  if (r == fr && c == fc) {
    pathCount++;
    return;
  }
  visited[r][c] = true;

  // Petunjuk 4 arah
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  // Cek 4 arah
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    // Validasi
    if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0 &&
        !visited[nr][nc]) {
      dfs(nr, nc, fr, fc, R, C, grid, visited, pathCount);
    }
  }
  // Backtrack
  visited[r][c] = false;
}

int main() {
  int R, C;
  cin >> R >> C;

  vector<vector<int>> grid(R, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> grid[i][j];
    }
  }

  int sr, sc, fr, fc;
  cin >> sr >> sc;
  cin >> fr >> fc;

  vector<vector<bool>> visited(R, vector<bool>(C, false));
  int pathCount = 0;
  dfs(sr, sc, fr, fc, R, C, grid, visited, pathCount);
  cout << pathCount << endl;

  return 0;
}
