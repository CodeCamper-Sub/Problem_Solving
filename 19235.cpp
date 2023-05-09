#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct Domino {
  ll score = 0, id = 1;
  vector<vector<ll>> grid;

  Domino() {
    grid.assign(4, vector<ll>(6, 0));
  }

  bool check() {
    bool result = false;
    for (ll i = 2; i < 6; i++) {
      bool all_same = true;
      for (ll j = 0; j < 4; j++) {
        if (grid[j][i] == 0) {
          all_same = false;
          break;
        }
      }
      if (all_same) {
        score++;
        result = true;
        for (ll j = 0; j < 4; j++)
          grid[j][i] = 0;
      }
    }
    return result;
  }

  void push_down() {
    for (ll i = 0; i < 4; i++) {
      ll cnt = 0;
      for (ll j = 5; j >= 0; j--) {
        if (grid[j][i] == 0)
          cnt++;
        else
          break;
      }
      for (ll j = 5; j - cnt >= 0; j--) {
        grid[j][i] = grid[j - cnt][i];
      }
    }
  }

  void move_all(ll k) {
    for (ll i = 0; i < 4; i++) {
      for (ll j = 5; j - k >= 0; j--) {
        grid[j][i] = grid[j - k][i];
      }
    }
  }

  void insert(ll t, ll y, ll x) {
    if (t == 1) {
      ll r = 0;
      while (r < 5 && grid[r + 1][x] == 0)
        r++;
      grid[r][x] = id++;
    } else if (t == 2) {
      ll r = 0;
      while (r < 5 && grid[r + 1][x] == 0 && grid[r + 1][x + 1] == 0)
        r++;
      grid[r][x] = id;
      grid[r][x + 1] = id++;
    } else {
      ll r = 0;
      while (r < 4 && grid[r + 1][x] == 0 && grid[r + 2][x] == 0)
        r++;
      grid[r][x] = id;
      grid[r + 1][x] = id++;
    }
    while (check()) {
      push_down();
    }
    ll cnt = 0;
    for (ll i = 1; i >= 0; i--) {
      for (ll j = 0; j < 4; j++) {
        if (grid[i][j] == 1) {
          cnt++;
          break;
        }
      }
    }
    if (cnt)
      move_all(cnt);
  }

  ll get_remain_cnt() {
    ll cnt = 0;
    for(ll i = 2; i < 6; i++) {
      for(ll j = 0; j < 4; j++) {
        if(grid[i][j]) cnt++;
      }
    }
    return cnt;
  }
};

Domino a, b;
ll n, t, x, y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(n--)  { 
    cin >> t >> y >> x;
    a.insert(t, y, x);
    ll bt, by, bx;
    if(t == 1) {
      bt = 1;
      by = x;
      bx = 3 - y;
    }
    else if(t == 2) {
      bt = 3;
      by = x;
      bx = 3 - y;
    }
    else if(t == 3) {
      bt = 2;
      by = x;
      bx = 2 - y;
    }
    b.insert(bt, by, bx);
  }

  cout << a.score + b.score << '\n';
  cout << a.get_remain_cnt() + b.get_remain_cnt() << '\n';

  return 0;
}