#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<vector<vector<ll>>> cube; // {x, y, z}
vector<vector<ll>> zy, xz, yx;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cube.resize(n);
  for_each(cube.begin(), cube.end(), [](auto& layer) {
    layer.assign(n, vector<ll>(n, 1));
  });

  zy.resize(n, vector<ll>(n));
  xz.resize(n, vector<ll>(n));
  yx.resize(n, vector<ll>(n));

  char c;
  for(ll z = n - 1; z >= 0; z--) {
    for(ll y = 0; y < n; y++) {
      cin >> c;
      zy[z][y] = c - '0';
      if(zy[z][y] == 0) {
        for(ll x = 0; x < n; x++) {
          cube[x][y][z] = 0;
        }
      }
    }
  }

  for(ll x = n - 1; x >= 0; x--) {
    for(ll z = 0; z < n; z++) {
      cin >> c;
      xz[x][z] = c - '0';
      if(xz[x][z] == 0) {
        for(ll y = 0; y < n; y++) {
          cube[x][y][z] = 0;
        }
      }
    }
  }

  for(ll y = n - 1; y >= 0; y--) {
    for(ll x = 0; x < n; x++) {
      cin >> c;
      yx[y][x] = c - '0';
      if(yx[y][x] == 0) {
        for(ll z = 0; z < n; z++) {
          cube[x][y][z] = 0;
        }
      }
    }
  }

  for(ll z = n - 1; z >= 0; z--) {
    for(ll y = 0; y < n; y++) {
      if(zy[z][y] == 1) {
        bool all_zero = true;
        for(ll x = 0; x < n; x++) {
          if(cube[x][y][z] == 1) {
            all_zero = false;
            break;
          }
        }
        if(all_zero) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }

  for(ll x = n - 1; x >= 0; x--) {
    for(ll z = 0; z < n; z++) {
      if(xz[x][z] == 1) {
        bool all_zero = true;
        for(ll y = 0; y < n; y++) {
          if(cube[x][y][z] == 1) {
            all_zero = false;
            break;
          }
        }
        if(all_zero) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }

  for(ll y = n - 1; y >= 0; y--) {
    for(ll x = 0; x < n; x++) {
      if(yx[y][x] == 1) {
        bool all_zero = true;
        for(ll z = 0; z < n; z++) {
          if(cube[x][y][z] == 1) {
            all_zero = false;
            break;
          }
        }
        if(all_zero) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }

  cout << "Yes\n";

  return 0;
}