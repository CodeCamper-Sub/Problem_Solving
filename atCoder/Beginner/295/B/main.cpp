#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll r, c;
char grid[30][30];

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c;
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
        cin >> grid[i][j];
    }
  }
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
        if(grid[i][j] >= '1' && grid[i][j] <= '9') {
            ll power = grid[i][j] - '0';
            for(ll y = 0; y < r; y++) {
                for(ll x = 0; x < c; x++) {
                    if(dist(i, j, y, x) <= power && grid[y][x] == '#') {
                        grid[y][x] = '.';
                    }
                }
            }
            grid[i][j] = '.';
        }
    }
  }

  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
        cout << grid[i][j];
    }
    cout << '\n';
  }
  
  return 0;
}