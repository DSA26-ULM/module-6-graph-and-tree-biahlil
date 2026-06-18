#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

  // Vertex / node
  int N;
  cin >> N;

  vector<char> label(N);
  for (int i = 0; i < N; i++) {
    cin >> label[i];
  }

  // Buat mapping char
  map<char, int> adj;
  for (int i = 0; i < N; i++) {
    adj[label[i]] = i;
  }

  // Inisialisasi matrix N x N dengan 0
  vector<vector<int>> matrix(N, vector<int>(N, 0));

  // Edge / Busur / panah
  int M;
  cin >> M;

  // Isi matrix
  for (int i = 0; i < M; i++) {
    char u, v;
    int w;
    cin >> u >> v >> w;
    matrix[adj[u]][adj[v]] = w;
  }

  // Cetak text header
  cout << "Adjacency Matrix:" << endl;

  // Cetak header matrix
  cout << "  ";
  for (int i = 0; i < N; i++) {
    if (i > 0)
      cout << " ";
    cout << label[i];
  }
  cout << endl;

  // Cetak setiap baris matrix
  for (int i = 0; i < N; i++) {
    cout << label[i];
    for (int j = 0; j < N; j++) {
      cout << " " << matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}
