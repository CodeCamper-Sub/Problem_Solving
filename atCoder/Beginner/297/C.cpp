#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll h, w;
vector<vector<char>> grid;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w;
  grid.assign(h, vector<char>(w));

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w - 1; j++) {
      if(grid[i][j] == 'T' && grid[i][j + 1] == 'T') {
        grid[i][j] = 'P';
        grid[i][j + 1] = 'C';
      }
    }
  }

  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
  
  return 0;
}