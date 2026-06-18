#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Banyak Label
  int N;
  cin >> N;

  // Baca Label Karakter
  vector<char> label(N);
  for (int i = 0; i < N; i++) {
    cin >> label[i];
  }

  // Baca Matrix adjacency
  vector<vector<int>> matrix(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  // Cetak header dan matrix adjacency list
  cout << "Adjacency List:" << endl;
  for (int i = 0; i < N; i++) {
    cout << label[i] << " -> ";
    bool hasEdge = false;
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] > 0) {
        if (hasEdge) {
          cout << ", ";
        }
        cout << "(" << label[j] << "," << matrix[i][j] << ")";
        hasEdge = true;
      }
    }
    if (!hasEdge) {
      cout << "-";
    }
    cout << endl;
  }

  return 0;
}
