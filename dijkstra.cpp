#include <cstdio>
#include <vector>

using namespace std;
const int inf = 1 << 30;

// given adjacency matrix adj, finds shortest path from A to B
int dijk(int A, int B, vector< vector<int> > adj) {
  int n = adj.size();
  vector<int> dist(n);
  vector<bool> vis(n);

  for(int i = 0; i < n; ++i) {
    dist[i] = inf;
  }
  dist[A] = 0;

  for(int i = 0; i < n; ++i) {
    int cur = -1;
    for(int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if (cur == -1 || dist[j] < dist[cur]) {
        cur = j;
      }
    }

    vis[cur] = true;
    for(int j = 0; j < n; ++j) {
      int path = dist[cur] + adj[cur][j];
      if (path < dist[j]) {
        dist[j] = path;
      }
    }
  }

  return dist[B];
}

#define _TEST
int main() {
  int N;
#ifndef _TEST
  printf("number of node: ");
  scanf("%d", &N);
#else
  N = 5;
#endif
  vector< vector<int> > adj(N);
  for(int i = 0; i < N; ++i) {
    adj[i] = vector<int>(N);
    for(int j = 0; j < N; ++j) {
      if (i == j)
        adj[i][j] = 0;
      else
        adj[i][j] = inf;
    }
  }

#ifndef _TEST
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      printf("adj[%d][%d]: ", i, j);
      scanf("%d", &(adj[i][j]));
    }
  }
#else
  adj[0][1] = 10;
  adj[0][2] = 3;
  adj[1][0] = 10;
  adj[1][2] = 5;
  adj[1][4] = 2;
  adj[2][0] = 3;
  adj[2][1] = 5;
  adj[2][3] = 2;
  adj[2][4] = 7;
  adj[3][2] = 2;
  adj[3][4] = 3;
  adj[4][1] = 2;
  adj[4][3] = 3;
#endif

  int ans = dijk(0, N - 1, adj);
  printf("%d\n", ans);
}

