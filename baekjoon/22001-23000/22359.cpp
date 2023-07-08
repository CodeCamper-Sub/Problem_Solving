#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll k, a, b;
vector<vector<char>> grid;

void init() {
  cin >> a >> b;
  a--; b--;
  grid.assign((1ll << k), vector<char>((1ll << k), '@'));
}

void recursive(ll y, ll x, ll l, ll type, char color) {
  if(l == 2) {
    if(type == 4) {
      ll new_type = 0;
      if(y + l / 2 > a) {
        if(x + l / 2 > b) {
          type = 0;
        } else {
          type = 1;
        }
      } else {
        if(x + l / 2 > b) {
          type = 2;
        } else {
          type = 3;
        }
      }
    }
    if(type != 0) grid[y][x] = color;
    if(type != 1) grid[y][x + 1] = color;
    if(type != 2) grid[y + 1][x] = color;
    if(type != 3) grid[y + 1][x + 1] = color;
    return;
  }
  if(l == 4) {
    if(type == 4) {
      ll new_type = 0;
      if(y + l / 2 > a) {
        if(x + l / 2 > b) {
          new_type = 0;
        } else {
          new_type = 1;
        }
      } else {
        if(x + l / 2 > b) {
          new_type = 2;
        } else {
          new_type = 3;
        }
      }
      if(new_type != 0) recursive(y, x, l / 2, 3, 'a');
      if(new_type != 1) recursive(y, x + l / 2, l / 2, 2, 'c');
      if(new_type != 2) recursive(y + l / 2, x, l / 2, 1, 'c');
      if(new_type != 3) recursive(y + l / 2, x + l / 2, l / 2, 0, 'a');
      recursive(y + l / 4, x + l / 4, l / 2, new_type, 'b');
      if(new_type == 0) recursive(y, x, l / 2, 4, 'a');
      if(new_type == 1) recursive(y, x + l / 2, l / 2, 4, 'c');
      if(new_type == 2) recursive(y + l / 2, x, l / 2, 4, 'c');
      if(new_type == 3) recursive(y + l / 2, x + l / 2, l / 2, 4, 'a');
    } else {
      if(type != 0) recursive(y, x, 2, 3, 'a');
      if(type != 1) recursive(y, x + 2, 2, 2, 'c');
      if(type != 2) recursive(y + 2, x, 2, 1, 'c');
      if(type != 3) recursive(y + 2, x + 2, 2, 0, 'a');
      recursive(y + 1, x + 1, 2, type, 'b');
      if(type == 0) recursive(y, x, l / 2, type, 'a');
      if(type == 1) recursive(y, x + l / 2, l / 2, type, 'c');
      if(type == 2) recursive(y + l / 2, x, l / 2, type, 'c');
      if(type == 3) recursive(y + l / 2, x + l / 2, l / 2, type, 'a');
    }
    return;
  }
  if(type == 4) {
    ll new_type = 0;
    if(y + l / 2 > a) {
      if(x + l / 2 > b) {
        new_type = 0;
      } else {
        new_type = 1;
      }
    } else {
      if(x + l / 2 > b) {
        new_type = 2;
      } else {
        new_type = 3;
      }
    }
    if(new_type != 0) recursive(y, x, l / 2, 3, 'a');
    if(new_type != 1) recursive(y, x + l / 2, l / 2, 2, 'c');
    if(new_type != 2) recursive(y + l / 2, x, l / 2, 1, 'c');
    if(new_type != 3) recursive(y + l / 2, x + l / 2, l / 2, 0, 'a');
    recursive(y + l / 4, x + l / 4, l / 2, new_type, color);
    if(new_type == 0) recursive(y, x, l / 2, 4, color);
    if(new_type == 1) recursive(y, x + l / 2, l / 2, 4, color);
    if(new_type == 2) recursive(y + l / 2, x, l / 2, 4, color);
    if(new_type == 3) recursive(y + l / 2, x + l / 2, l / 2, 4, color);
  } else {
    if(type != 0) recursive(y, x, l / 2, 3, 'a');
    if(type != 1) recursive(y, x + l / 2, l / 2, 2, 'c');
    if(type != 2) recursive(y + l / 2, x, l / 2, 1, 'c');
    if(type != 3) recursive(y + l / 2, x + l / 2, l / 2, 0, 'a');
    recursive(y + l / 4, x + l / 4, l / 2, type, color);
    if(type == 0) recursive(y, x, l / 2, type, color);
    if(type == 1) recursive(y, x + l / 2, l / 2, type, color);
    if(type == 2) recursive(y + l / 2, x, l / 2, type, color);
    if(type == 3) recursive(y + l / 2, x + l / 2, l / 2, type, color);
  }
}

void solve() {
  recursive(0, 0, (1ll << k), 4, 'a');
  grid[a][b] = '@';
  for(ll i = 0; i < (1ll << k); i++) {
    for(ll j = 0; j < (1ll << k); j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt >> k;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}