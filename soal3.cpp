#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;

  // grid R x C
  vector<vector<int>> grid(R, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> grid[i][j];
    }
  }

  // posisi awal dan tujuan
  int sr, sc, fr, fc;
  cin >> sr >> sc;
  cin >> fr >> fc;

  // Inisialisasi visited dan dist
  vector<vector<bool>> visited(R, vector<bool>(C, false));
  vector<vector<int>> dist(R, vector<int>(C, -1));

  // Definisikan 4 arah pergerakan
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  // Inisialisasi queue dan push start
  queue<pair<int, int>> q;
  q.push({sr, sc});
  visited[sr][sc] = true;
  dist[sr][sc] = 0;

  //  BFS Loop
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    // Cek apakah sudah sampai tujuan
    if (r == fr && c == fc) {
      cout << dist[r][c] << endl;
      return 0;
    }

    // Cek 4 arah
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      // Validasi batas grid + bukan dinding + belum visited
      if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0 &&
          !visited[nr][nc]) {
        visited[nr][nc] = true;
        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
