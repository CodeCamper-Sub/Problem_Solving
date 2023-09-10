#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<ll> order;
vector<vector<ll>> grid;

bool willDisappoint(vector<vector<ll>>& now, ll y, ll x) {
  // 같은 행
  vector<ll> r;
  for(ll j = 0; j < 3; j++) {
    if(now[y][j] != -1) r.push_back(now[y][j]);
  }
  if(r.size() == 2 && r[0] == r[1] && r[0] != grid[y][x]) { return true; }

  vector<ll> c;
  for(ll i = 0; i < 3; i++) {
    if(now[i][x] != -1) c.push_back(now[i][x]);
  }
  if(c.size() == 2 && c[0] == c[1] && c[0] != grid[y][x]) { return true; }

  if(x == 1 && y == 1) {
    vector<ll> d;
    for(ll i = 0; i < 3; i++) {
      if(now[i][i] != -1) d.push_back(now[i][i]);
    }
    if(d.size() == 2 && d[0] == d[1] && d[0] != grid[y][x]) return true;

    d.clear();
    for(ll i = 0; i < 3; i++) {
      if(now[i][2 - i] != -1) d.push_back(now[i][2 - i]);
    }
    if(d.size() == 2 && d[0] == d[1] && d[0] != grid[y][x]) return true;
    return false;
  } else if((y == 0 && x == 0) || (y == 2 && x == 2)) {
    vector<ll> d;
    for(ll i = 0; i < 3; i++) {
      if(now[i][i] != -1) d.push_back(now[i][i]);
    }
    if(d.size() == 2 && d[0] == d[1] && d[0] != grid[y][x]) return true;
    return false;
  }else if((y == 0 && x == 2) || (y == 2 && x == 0)) {
    vector<ll> d;
    for(ll i = 0; i < 3; i++) {
      if(now[i][2 - i] != -1) d.push_back(now[i][2 - i]);
    }
    if(d.size() == 2 && d[0] == d[1] && d[0] != grid[y][x]) return true;
    return false;
  } else return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  grid.assign(3, vector<ll>(3));
  for(ll i = 0; i < 3; i++) for(ll j = 0; j < 3; j++) cin >> grid[i][j];
  order.resize(9);
  iota(order.begin(), order.end(), 0);

  ll cnt = 0;
  do {
    vector<vector<ll>> now;
    now.assign(3, vector<ll>(3, -1));
    bool is_valid = true;
    for(ll o: order) {
      if(willDisappoint(now, o / 3, o % 3)) {
        is_valid = false;
        break;
      } else {
        now[o / 3][o % 3] = grid[o / 3][o % 3];
      }
    }
    if(is_valid) 
      cnt++;
  } while(next_permutation(order.begin(), order.end()));

  // 362880
  cout << fixed;
  cout.precision(30);
  cout << double(cnt) / double(362880) << '\n';

  
  return 0;
}