#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll h, w;
vector<vector<char>> grid;
vector<vector<pair<ll, double>>> e;
vector<double> visited;

ll flatten(ll y, ll x) {
  return y * (2 * w + 1) + x;
}

void make_edge(ll a, ll b, double dist) {
  e[a].push_back({b, dist});
  e[b].push_back({a, dist});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  e.resize((2 * h + 1) * (2 * w + 1));
  for(ll y = 0; y < 2 * h + 1; y += 2) {
    for(ll x = 0; x < 2 * w; x++) {
      make_edge(flatten(y, x), flatten(y, x + 1), 5.0);
    }
  }

  for(ll x = 0; x < 2 * w + 1; x += 2) {
    for(ll y = 0; y < 2 * h; y++) {
      make_edge(flatten(y, x), flatten(y + 1, x), 5.0);
    }
  }

  grid.assign(h, vector<char>(w));
  for(ll i = 0; i < h; i++) for(ll j = 0; j < w; j++) {
    cin >> grid[i][j];
    if(grid[i][j] == 'O') {
      ll y = 2 * i, x = 2 * j;
      make_edge(flatten(y, x + 1), flatten(y + 1, x + 2), 2.5 * M_PI);
      make_edge(flatten(y + 1, x + 2), flatten(y + 2, x + 1), 2.5 * M_PI);
      make_edge(flatten(y + 2, x + 1), flatten(y + 1, x), 2.5 * M_PI);
      make_edge(flatten(y + 1, x), flatten(y, x + 1), 2.5 * M_PI);
    }
  }

  visited.assign((2 * h + 1) * (2 * w + 1), __INT_MAX__);
  queue<ll> q;
  q.push(0);
  visited[0] = 0;
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(auto [next, dist]: e[now]) {
      if(visited[next] > visited[now] + dist) {
        visited[next] = visited[now] + dist;
        q.push(next);
      }
    }
  }

  cout << fixed;
  cout.precision(10);
  cout << visited[(2 * h + 1) * (2 * w + 1) - 1] << '\n';

  
  return 0;
}