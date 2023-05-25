#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll h, w;
vector<vector<char>> grid[3];

bool check() {
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      if(grid[1][i][j] != grid[2][i][j]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  grid[0].assign(h, vector<char>(w));
  grid[1].assign(h, vector<char>(w));
  grid[2].assign(h, vector<char>(w));

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> grid[0][i][j];
    }
  }
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> grid[1][i][j];
    }
  }
  for(ll s = 0; s < h; s++) {
    for(ll t = 0; t < w; t++) {
      for(ll i = 0; i < h; i++) {
        for(ll j = 0; j < w; j++) {
          grid[2][(i + s) % h][(j + t) % w] = grid[0][i][j];
        }
      }
      if(check()) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  
  return 0;
}